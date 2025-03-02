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
  vector<int> V(n), A(n), C(n);
  rep(i, n) {
    cin >> V[i] >> A[i] >> C[i];
  }
  vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(n+1, vector<ll>(x+1, 0)));
  rep(i, n) {
    rep(j, x+1) {
      rep(k, 3) {
        chmax(dp[k][i+1][j], dp[k][i][j]);
        if(V[i] == k+1 && j+C[i] <= x) {
          chmax(dp[k][i+1][j+C[i]], dp[k][i][j]+A[i]);
        }
      }
    }
    rep(j, x) {
      rep(k, 3) {
        chmax(dp[k][i+1][j+1], dp[k][i+1][j]);
      }
    }
  }
  auto bsearch = [&]() {
    auto test = [&](ll t) {
      ll sum = 0;
      rep(k, 3) {
        sum += (lower_bound(all(dp[k][n]), t) - begin(dp[k][n]));
      }
      return sum <= x;
    };
    ll ok = 0, ng = longinf;
    while(ng-ok > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
