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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  set<int> st;
  int ans = 0;
  int l = 0, r = 0;
  while(l < n) {
    chmax(r, l);
    while(r+1 < n && A[r] == A[r+1] && !st.count(A[r])) {
      st.insert(A[r]);
      r += 2;
    }
    chmax(ans, r-l);
    if(r >= n-1) {
      break;
    } else if(r+1 < n && A[r] != A[r+1]) {
      if(l <= r-1 && A[r-1] == A[r]) {
        st.clear();
        st.insert(A[r-1]);
        l = r-1;
        r = r+1;
      } else {
        st.clear();
        l = r+1;
      }
    } else {
      while(l < r && st.count(A[r])) {
        st.erase(A[l]);
        l += 2;
      }
    }
  }
  cout << ans << endk;
  return 0;
}
