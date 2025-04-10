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
  int q; cin >> q;
  int mx = 1000001;
  vector<bool> is_prime(mx, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> cnt(mx);
  REP(i, 2, mx) {
    if(!is_prime[i]) continue;
    cnt[i]++;
    for(int j=0; i*(j+2)<mx; j++) {
      is_prime[i*(j+2)] = false;
      cnt[i*(j+2)]++;
    }
  }
  vector<int> ok;
  rep(i, mx) {
    if(cnt[i] == 2) {
      ok.push_back(i);
    }
  }
  rep(i, q) {
    ll a; cin >> a;
    int rt = sqrt(a);
    int b = *--upper_bound(all(ok), rt);
    cout << 1LL*b*b << endk;
  }
  return 0;
}
