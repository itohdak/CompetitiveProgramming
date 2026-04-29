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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(n/2);
  rep(i, n/2) {
    B[i] = (A[i]-A[n-1-i]+m)%m;
  }
  vector<int> C(n/2+1);
  rep(i, n/2+1) {
    C[i] = ((i==n/2 ? 0 : B[i]) - (i==0 ? 0 : B[i-1]) + m) % m;
  }
  sort(all(C));
  ll ans = longinf;
  ll cum1 = 0, cum2 = 0;
  rep(i, C.size()) cum2 += m-C[i];
  ans = cum2;
  rep(i, C.size()) {
    cum1 += C[i];
    cum2 -= m-C[i];
    chmin(ans, max(cum1, cum2));
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
