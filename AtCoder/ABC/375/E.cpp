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
  int sum = 0;
  vector<int> A(n), B(n);
  rep(i, n) {
    cin >> A[i]; A[i]--;
    cin >> B[i];
    sum += B[i];
  }
  if(sum % 3) {
    cout << -1 << endk;
    return 0;
  }
  int trgt = sum / 3;
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(trgt+1, vector<int>(trgt+1, inf)));
  dp[0][0][0] = 0;
  int tmp = 0;
  rep(i, n) {
    tmp += B[i];
    rep(j, 3) {
      rep(k, trgt+1) {
        rep(l, trgt+1) {
          int k2 = k + (j==0 ? B[i] : 0);
          int l2 = l + (j==1 ? B[i] : 0);
          int rest = tmp - k2 - l2;
          if(k2 <= trgt && l2 <= trgt && rest <= trgt) {
            chmin(dp[i+1][k2][l2], dp[i][k][l]+(A[i]!=j));
          }
        }
      }
    }
  }
  cout << (dp[n][trgt][trgt]==inf ? -1 : dp[n][trgt][trgt]) << endk;
  return 0;
}
