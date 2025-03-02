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
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  map<pair<int, int>, int> memo;
  auto dfs = [&](auto dfs, int cur, int par) -> int {
    if(par != -1) {
      if(memo.count({cur, par})) return memo[{cur, par}];
      if(G[cur].size()-1 < 3) {
        return memo[{cur, par}] = 1;
      } else {
        vector<int> v;
        for(int ne: G[cur]) {
          if(ne == par) continue;
          v.push_back(dfs(dfs, ne, cur));
        }
        sort(all(v), greater<int>());
        memo[{cur, par}] = 1;
        rep(i, 3) {
          memo[{cur, par}] += v[i];
        }
        return memo[{cur, par}];
      }
    } else {
      int ret = 0;
      for(int ne: G[cur]) {
        chmax(ret, dfs(dfs, ne, cur));
      }
      ret++;
      return ret;
    }
  };
  int mx = 0;
  rep(i, n) chmax(mx, dfs(dfs, i, -1));
  if(mx < 5) {
    cout << -1 << endk;
  } else {
    cout << mx << endk;
  }
  return 0;
}
