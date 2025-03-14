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
  int n, x; cin >> n >> x;
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<vector<ld>> dp(n+1, vector<ld>(n+1));
  dp[0][0] = 1;
  rep(i, n) {
    ld p = (ld)1 * P[i] / 100;
    rep(j, n+1) {
      dp[i+1][min(j+1, n)] += dp[i][j] * p;
      dp[i+1][j] += dp[i][j] * (1-p);
    }
  }
  vector<ld> dp2(x+1);
  REP(i, 1, x+1) {
    ld sum = 0;
    REP(j, 1, n+1) {
      if(i-j < 0) break;
      sum += dp2[max(0, i-j)] * dp[n][j];
    }
    dp2[i] = (1 + sum) / (1 - dp[n][0]);
  }
  cout << fixed << setprecision(10) << dp2[x] << endk;
  return 0;
}
