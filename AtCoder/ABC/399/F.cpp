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

using mint = modint998244353;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<mint> A(n);
  rep(i, n) {
    int a; cin >> a;
    A[i] = a;
  }
  vector<mint> cum(n+1);
  rep(i, n) {
    cum[i+1] = cum[i] + A[i];
  }
  vector<vector<mint>> pw(k, vector<mint>(n+1));
  vector<mint> S(k);
  rep(j, k) {
    rep(i, n+1) {
      if(j == 0) pw[j][i] = 1;
      else if(j == 1) pw[j][i] = cum[i];
      else if(j > 1) pw[j][i] = pw[j-1][i] * pw[1][i];
      S[j] += pw[j][i];
    }
  }
  vector<vector<mint>> comb(k+1, vector<mint>(k+1));
  rep(i, k+1) {
    comb[i][0] = 1;
    rep(j, i) {
      comb[i][j+1] = comb[i][j] * (i-j) / (j+1);
    }
  }
  mint cur = 0;
  rep(i, n) {
    mint tmp = 1;
    rep(j, k) tmp *= cum[i+1];
    cur += tmp;
  }
  mint ans = 0;
  rep(i, n) {
    ans += cur;
    rep(j, k) {
      // TODO
    }
    mint tmp = 1;
    rep(j, k) tmp *= A[i];
    mint modinv = (A[i]==0 ? 1 : 1/A[i]);
    mint tmp2 = 1;
    rep(j, k) {
      cur -= comb[k][j] * tmp * S[j] * (j==0 ? (n-i) : 1);
      tmp *= modinv;
    }
  }
  cout << ans.val() << endk;
  return 0;
}
