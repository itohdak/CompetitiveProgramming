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
  string s; cin >> s;
  int n = s.size();
  vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(26, vector<ll>(n+1)));
  rep(i, n) {
    dp[1][s[i]-'A'][i+1]++;
    rep(j, 26) {
      dp[1][j][i+1] += dp[1][j][i];
      dp[2][j][i+1] += dp[2][j][i];
      dp[3][j][i+1] += dp[3][j][i];
      dp[2][j][i+1] += dp[1][j][i];
    }
    dp[3][s[i]-'A'][i+1] += dp[2][s[i]-'A'][i];
  }
  ll ans = 0;
  rep(i, 26) {
    ans += dp[3][i][n];
  }
  cout << ans << endk;
  return 0;
}
