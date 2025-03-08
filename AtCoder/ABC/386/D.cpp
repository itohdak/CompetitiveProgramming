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
  int n, m; cin >> n >> m;
  vector<int> X(m), Y(m);
  vector<char> C(m);
  vector<tuple<int, int, int>> A;
  rep(i, m) {
    cin >> X[i] >> Y[i] >> C[i];
    X[i]--; Y[i]--;
    A.push_back({X[i], Y[i], C[i]=='B'});
  }
  sort(all(A));
  int i = 0;
  int mn = INT_MAX;
  bool ok = true;
  while(i < A.size()) {
    int j = i;
    while(j < A.size() && get<0>(A[j]) == get<0>(A[i])) {
      auto [x, y, c] = A[j];
      if(c == 0) {
        chmin(mn, y);
      } else {
        if(y >= mn) {
          ok = false;
        }
      }
      j++;
    }
    i = j;
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
