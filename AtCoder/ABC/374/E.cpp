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
  vector<int> A(n), P(n), B(n), Q(n);
  rep(i, n) {
    cin >> A[i] >> P[i] >> B[i] >> Q[i];
  }
  auto bsearch = [&]() -> ll {
    auto test = [&](ll t) -> bool {
      ll cost = 0;
      rep(i, n) {
        ll tmp = longinf;
        if(1LL*A[i]*Q[i] < 1LL*B[i]*P[i]) {
          swap(A[i], B[i]);
          swap(P[i], Q[i]);
        }
        int mx = (t+A[i]-1)/A[i];
        for(int c=max(0, mx-100); c<=mx; c++) {
          chmin(tmp, 1LL*P[i]*c+Q[i]*max(0LL, (t-A[i]*c+B[i]-1)/B[i]));
        }
        cost += tmp;
      }
      return cost <= x;
    };
    ll ok = 0, ng = inf;
    while(ng-ok > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
