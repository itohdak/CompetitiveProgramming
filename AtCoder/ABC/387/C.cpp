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
  ll l, r; cin >> l >> r;
  auto count = [&](ll n) -> ll {
    vector<int> D;
    while(n) {
      D.push_back(n%10);
      n /= 10;
    }
    int d = D.size();
    vector<vector<vector<vector<ll>>>> dp(d+1, vector<vector<vector<ll>>>(10, vector<vector<ll>>(10, vector<ll>(2))));
    rrep(i, d) {
      for(int j=1; j<10; j++) {
        for(int k=0; k<j; k++) {
          for(int l=0; l<=j; l++) {
            rep(m, 2) {
              if(m == 0 && k > D[i]) continue;
              dp[i][j][k][(k < D[i] || m)] += dp[i+1][j][l][m];
            }
          }
        }
        if(i == d-1 && j > D[i]) continue;
        dp[i][j][j][(j < D[i] || i < d-1)] += 1;
      }
    }
    ll ans = 0;
    for(int j=1; j<10; j++) {
      for(int k=0; k<=j; k++) {
        rep(m, 2) {
          ans += dp[0][j][k][m];
        }
      }
    }
    return ans;
  };
  cout << count(r)-count(l-1) << endk;
  return 0;
}
