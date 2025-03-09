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
  vector<ll> X(n), H(n);
  rep(i, n) cin >> X[i] >> H[i];
  ld ans = -1;
  rep(i, n-1) {
    ld h = (ld)((H[i+1]*X[i])-(H[i]*X[i+1]))/(X[i]-X[i+1]);
    chmax(ans, h);
  }
  if(ans < 0) {
    cout << -1 << endk;
  } else {
    cout << fixed << setprecision(20) << max((ld)0, ans) << endk;
  }
  return 0;
}
