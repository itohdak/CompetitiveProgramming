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
  int n, q; cin >> n >> q;
  int l = 0, r = 1;
  int ans = 0;
  rep(i, q) {
    char h; cin >> h;
    int t; cin >> t; t--;
    if(h == 'L') {
      if(l < t) {
        if(l < r && r < t) {
          ans += n-(t-l);
        } else {
          ans += (t-l);
        }
      } else {
        if(t < r && r < l) {
          ans += n-(l-t);
        } else {
          ans += (l-t);
        }
      }
      l = t;
    } else {
      if(r < t) {
        if(r < l && l < t) {
          ans += n-(t-r);
        } else {
          ans += (t-r);
        }
      } else {
        if(t < l && l < r) {
          ans += n-(r-t);
        } else {
          ans += (r-t);
        }
      }
      r = t;
    }
  }
  cout << ans << endk;
  return 0;
}
