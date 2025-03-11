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
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> D(26);
  ll ans = 0;
  ll pw = 1;
  rep(_, 25) pw *= 2;
  for(int k=25; k>=0; k--) {
    map<ll, int> cnt;
    map<ll, ll> sum;
    rep(i, n) {
      ll m = ((-A[i]%pw)+pw)%pw;
      cnt[m]++;
      sum[m] += A[i];
      ll m0 = A[i]%pw;
      if(cnt.count(m0)) {
        D[k] += cnt[m0] * A[i] + sum[m0];
      }
    }
    if(k < 25) ans += (D[k]-D[k+1])/pw;
    pw /= 2;
  }
  cout << ans << endk;
  return 0;
}
