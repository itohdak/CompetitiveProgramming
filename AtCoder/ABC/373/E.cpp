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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  if(n == m) {
    rep(i, n) cout << 0 << ' ';
    cout << endk;
    return 0;
  }
  ll rem = k;
  rep(i, n) {
    rem -= A[i];
  }
  auto tmp = A;
  sort(all(tmp));
  vector<ll> cum(n+1);
  rep(i, n) cum[i+1] = cum[i] + tmp[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return A[i] < A[j];
  });
  vector<ll> ans(n);
  rep(i, n) {
    int j = id[i];
    ll hi = A[j] + rem;
    if(end(tmp) - lower_bound(all(tmp), hi+1) >= m) {
      ans[j] = -1;
      continue;
    }
    auto test = [&](ll t) -> bool {
      ll hi = A[j] + t;
      int p = lower_bound(all(tmp), hi+1) - begin(tmp);
      return (hi+1) * (m-(n-p)) - (cum[p] - cum[n-m-(i>=n-m)] - (i>=n-m ? A[j] : 0)) > rem - t && n - p < m;
    };
    ll ok = rem, ng = -1;
    while(ok-ng > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    ans[j] = ok;
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
