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
// const ll mod = 1e9+7;
// const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

using mint = modint998244353;
const ll mod = 998244353;
#define MAX_N 2000005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod;
  return ans;
}

int main() {
  make();
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int m = (n+1)/2;
  vector<int> L(n), R(n);
  vector<tuple<int, int, int>> Q;
  rep(i, n) {
    cin >> L[i] >> R[i];
    int l1 = L[i], r1 = R[i], l2 = n-R[i], r2 = n-L[i];
    if(r1+1 <= m) {
      Q.push_back({l1, 0, 1});
      Q.push_back({r1+1, 1, -1});
    } else if(l1 > m) {
      Q.push_back({l2, 0, 3});
      Q.push_back({r2+1, 3, -1});
    } else if(l1 < l2) {
      Q.push_back({l1, 0, 1});
      Q.push_back({l2, 1, 2});
    } else {
      Q.push_back({l2, 0, 3});
      Q.push_back({l1, 3, 2});
    }
  }
  sort(all(Q));
  int cnt1, cnt2, cnt3;
  cnt1 = cnt2 = cnt3 = 0;
  int l = 0;
  mint ans = 0;
  for(int i=1; i<=n-i; i++) {
    while(l < Q.size() && get<0>(Q[l]) <= i) {
      auto [p, t1, t2] = Q[l];
      if(t1 == 1) cnt1--;
      else if(t1 == 2) cnt2--;
      else if(t1 == 3) cnt3--;
      if(t2 == 1) cnt1++;
      else if(t2 == 2) cnt2++;
      else if(t2 == 3) cnt3++;
      l++;
    }
    if(cnt1 + cnt2 + cnt3 < n || cnt1 > i || cnt3 > n-i) continue;
    ans += comb(cnt2, i-cnt1) * (n-i == i ? 1 : 2);
  }
  cout << ans.val() << endk;
  return 0;
}
