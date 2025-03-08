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
  int k; cin >> k;
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  if(abs(n-m) > k) {
    cout << "No" << endk;
    return 0;
  }
  vector<vector<int>> dp(n+1, vector<int>(2*k+1, inf));
  dp[0][k] = 0;
  rep(i, n+1) {
    rep(dj, 2*k+1) {
      int j = i + dj - k;
      if(j < 0) continue;
      if(j > m) break;
      if(i > 0 && dj < 2*k) {
        chmin(dp[i][dj], dp[i-1][dj+1]+1);
      }
      if(j > 0 && dj > 0) {
        chmin(dp[i][dj], dp[i][dj-1]+1);
      }
      if(i > 0 && j > 0) {
        chmin(dp[i][dj], dp[i-1][dj]+(s[i-1]!=t[j-1]));
      }
    }
  }
  cout << (dp[n][m-n+k]<=k ? "Yes" : "No") << endk;
  return 0;
}
