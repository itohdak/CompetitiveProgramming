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
  int n, m; cin >> n >> m;
  vector<int> B(n); rep(i, n) cin >> B[i];
  vector<int> W(m); rep(i, m) cin >> W[i];
  sort(all(B), greater<int>());
  sort(all(W), greater<int>());
  vector<ll> cumB(n+1), cumW(m+1);
  rep(i, n) cumB[i+1] = cumB[i] + B[i];
  rep(i, m) cumW[i+1] = cumW[i] + W[i];
  ll ans = -longinf;
  ll mx = -longinf;
  rep(i, n+1) {
    if(i < m+1) chmax(mx, cumW[i]);
    ll tmp = cumB[i] + mx;
    chmax(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
