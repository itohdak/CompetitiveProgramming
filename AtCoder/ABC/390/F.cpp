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
  vector<int> A(n);
  vector<vector<int>> pos(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
    pos[A[i]].push_back(i);
  }
  ll ans = 0;
  set<int> st;
  st.insert(-1);
  st.insert(n);
  rep(i, n) {
    for(int p: pos[i]) {
      ll l = p-*(--st.upper_bound(p));
      ll r = *st.lower_bound(p)-p;
      ans += l*r;
      st.insert(p);
    }
    if(i-1 >= 0) {
      for(int p: pos[i-1]) {
        st.erase(p);
      }
    }
  }
  cout << ans << endk;
  return 0;
}
