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
  int n, q; cin >> n >> q;
  vector<int> C(q), P(q);
  rep(i, q) cin >> C[i] >> P[i];
  vector<set<int>> G(n+1);
  vector<int> par(n+1);
  rep(i, n) {
    G[0].insert(i+1);
    par[i+1] = 0;
  }
  rep(i, q) {
    G[par[C[i]]].erase(C[i]);
    G[P[i]].insert(C[i]);
    par[C[i]] = P[i];
  }
  vector<int> ans(n);
  for(int r: G[0]) {
      ans[r-1] = 1;
      int cur = r;
      while(G[cur].size()) {
        ans[r-1]++;
        assert(G[cur].size() == 1);
        cur = *G[cur].begin();
      }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
