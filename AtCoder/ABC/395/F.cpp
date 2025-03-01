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
  vector<int> U(n), D(n);
  ll mn = longinf;
  rep(i, n) {
    cin >> U[i] >> D[i];
    chmin(mn, U[i]+D[i]);
  }
  auto bsearch = [&]() -> ll {
    auto test = [&](ll t) -> bool {
      ll lb = 0, ub = longinf;
      rep(i, n) {
        ll next_lb = max(0LL, U[i]-(U[i]+D[i]-t));
        ll next_ub = U[i];
        lb = max(lb-x, next_lb);
        ub = min(ub+x, next_ub);
        if(lb > ub) break;
      }
      return lb <= ub;
    };
    ll ok = 0, ng = mn+1;
    while(ng-ok > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll h = bsearch();
  ll ans = 0;
  rep(i, n) ans += U[i]+D[i]-h;
  cout << ans << endk;
  return 0;
}
