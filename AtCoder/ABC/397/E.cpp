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
  int n, k; cin >> n >> k;
  vector<vector<int>> G(n*k);
  rep(i, n*k-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bool ok = true;
  vector<int> len(n*k);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    int cnt = 0;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      if(len[ne]) {
        cnt++;
        len[cur] += len[ne];
      }
    }
    if(cnt > 2) {
      ok = false;
    } else if(cnt == 2) {
      if(len[cur]+1 != k) {
        ok = false;
      } else {
        len[cur] = 0;
      }
    } else {
      if(++len[cur] == k) {
        len[cur] = 0;
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
