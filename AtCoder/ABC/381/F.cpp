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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> pos(21);
  rep(i, n) {
    A[i]--;
    pos[A[i]].push_back(i);
  }
  vector<int> dp(1<<20, inf);
  dp[0] = 0;
  rep(i, 1<<20) {
    if(dp[i] == inf) continue;
    rep(j, 20) {
      if((i>>j)&1) continue;
      int k = lower_bound(all(pos[j]), dp[i]) - begin(pos[j]);
      if(k+1 >= pos[j].size()) continue;
      chmin(dp[i^1<<j], pos[j][k+1]+1);
    }
  }
  int ans = 0;
  rep(i, 1<<20) {
    if(dp[i] != inf) {
      chmax(ans, __builtin_popcount(i)*2);
    }
  }
  cout << ans << endk;
  return 0;
}
