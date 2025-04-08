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
  int n, s, t; cin >> n >> s >> t;
  vector<int> A(n), B(n), C(n), D(n);
  rep(i, n) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  vector<int> id(n);
  iota(all(id), 0);
  ld ans = longinf;
  do {
    rep(j, 1<<n) {
      int x = 0, y = 0;
      ld tmp = 0;
      rep(k, n) {
        int i = id[k];
        int nx = ((j>>k)&1 ? A[i] : C[i]);
        int ny = ((j>>k)&1 ? B[i] : D[i]);
        int dx = x-nx;
        int dy = y-ny;
        tmp += sqrt(dx*dx+dy*dy) / s;
        tmp += sqrt((A[i]-C[i])*(A[i]-C[i])+(B[i]-D[i])*(B[i]-D[i])) / t;
        x = A[i]+C[i]-nx, y = B[i]+D[i]-ny;
      }
      chmin(ans, tmp);
    }
  } while(next_permutation(all(id)));
  cout << fixed << setprecision(10) << ans << endk;
  return 0;
}
