#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<pair<int, ll>>> G(n);
  rep(i, m) {
    int u, v; ll w; cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  vector<bool> vis(n);
  ll ans = longinf;
  ll x = 0;
  auto dfs = [&](auto dfs, int cur) -> void {
    if(cur == n-1) {
      chmin(ans, x);
      return;
    }
    for(auto [ne, w]: G[cur]) {
      if(vis[ne]) continue;
      vis[ne] = true;
      x ^= w;
      dfs(dfs, ne);
      x ^= w;
      vis[ne] = false;
    }
  };
  vis[0] = true;
  dfs(dfs, 0);
  cout << ans << endk;
  return 0;
}
