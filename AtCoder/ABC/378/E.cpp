#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    A[i] %= m;
  }
  fenwick_tree<int> bit(m);
  vector<ll> cum(n+1);
  ll tmp = 0;
  rep(i, n) {
    cum[i+1] = cum[i] + A[i];
    bit.add(cum[i+1]%m, 1);
    tmp += cum[i+1]%m;
  }
  ll ans = 0;
  rep(i, n) {
    ans += tmp;
    tmp -= 1LL * (A[i]%m) * (n-i);
    if(cum[i]%m < cum[i+1]%m) {
      tmp += 1LL * m * bit.sum(cum[i]%m, cum[i+1]%m);
    } else if(cum[i]%m > cum[i+1]%m) {
      tmp += 1LL * m * (bit.sum(0, cum[i+1]%m) + bit.sum(cum[i]%m, m));
    }
    bit.add(cum[i+1]%m, -1);
  }
  cout << ans << endk;
  return 0;
}
