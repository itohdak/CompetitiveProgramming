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
  ll n; cin >> n;
  for(ll d=1; d<=1000000; d++) {
    if(n%d) continue;
    // 3*d*k^2 + 3*d^2*k + d^3-n = 0
    auto bsearch = [&]() {
      auto test = [&](ll k) {
        return 3*k*k + 3*d*k + d*d <= n/d;
      };
      ll ok = 0, ng = 1000000000;
      while(abs(ok-ng) > 1) {
        ll mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    ll k = bsearch();
    if(k == 0) continue;
    if(3*k*k + 3*d*k + d*d == n/d) {
      cout << d+k << ' ' << k << endk;
      return 0;
    }
  }
  cout << -1 << endk;
  return 0;
}
