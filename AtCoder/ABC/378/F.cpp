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
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> cnt(n);
  ll ans = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
      int sum = 0;
      ll pwsum = 0;
      int sum2 = 0;
      for(int ne: G[cur]) {
        if(ne == par) continue;
        dfs(dfs, ne, cur);
        if(cnt[ne] != 0) {
          sum += cnt[ne];
          pwsum += 1LL*cnt[ne]*cnt[ne];
          if(G[ne].size() == 2) sum2++;
        }
      }
      if(G[cur].size() == 2) {
        ans += sum-sum2;
      } else if(G[cur].size() == 3) {
        ans += (1LL*sum*sum - pwsum) / 2;
      }
      if(G[cur].size() == 2) {
        cnt[cur] = 1;
      } else if(G[cur].size() == 3) {
        cnt[cur] = sum;
      } else {
        cnt[cur] = 0;
      }
  };
  dfs(dfs, 0, -1);
  cout << ans << endk;
  return 0;
}
