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
  int n, x, k; cin >> n >> x >> k;
  vector<int> P(n), U(n), C(n);
  set<int> st;
  rep(i, n) {
    cin >> P[i] >> U[i] >> C[i];
    st.insert(C[i]);
  }
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    if(C[i] == C[j]) return i < j;
    else return C[i] < C[j];
  });
  int nc = st.size();
  int i = 0;
  int c = 0;
  vector<vector<ll>> dp(nc+1, vector<ll>(x+1));
  while(i < n) {
    int j = i;
    while(j < n && C[id[j]] == C[id[i]]) {
      auto pj = P[id[j]];
      auto uj = U[id[j]];
      for(int p=x; p>=pj; p--) {
        chmax(dp[c+1][p], dp[c][p-pj]+uj+k);
        chmax(dp[c+1][p], dp[c+1][p-pj]+uj);
      }
      j++;
    }
    rep(p, x+1) {
      chmax(dp[c+1][p], dp[c][p]);
    }
    i = j;
    c++;
  }
  cout << dp[nc][x] << endk;
  return 0;
}
