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
  vector<pair<int, int>> A(m);
  rep(i, m) {
    auto& [x, _] = A[i];
    cin >> x;
    x--;
  }
  rep(i, m) {
    auto& [_, a] = A[i];
    cin >> a;
  }
  sort(all(A));
  if(A[0].first != 0) {
    cout << -1 << endk;
    return 0;
  }
  ll sum = 0;
  ll sum2 = 0;
  rep(i, m) {
    sum += A[i].second;
    sum2 += 1LL * A[i].first * A[i].second;
    int r = (i==m-1 ? n : A[i+1].first);
    if(r > sum) {
      cout << -1 << endk;
      return 0;
    }
  }
  if(sum != n) {
    cout << -1 << endk;
    return 0;
  }
  cout << (1LL*n*(n-1)/2 - sum2) << endk;
  return 0;
}
