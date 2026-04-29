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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  vector<int> A(n+1), B(n+1), C(n+1);
  rep(i, n) {
    A[i+1] = A[i] + (s[i] == 'A');
    B[i+1] = B[i] + (s[i] == 'B');
    C[i+1] = C[i] + (s[i] == 'C');
  }
  map<int, int> mpAB, mpBC, mpCA;
  map<pair<int, int>, int> mpABC;
  rep(i, n+1) {
    mpAB[A[i] - B[i]]++;
    mpBC[B[i] - C[i]]++;
    mpCA[C[i] - A[i]]++;
    mpABC[{A[i] - B[i], B[i] - C[i]}]++;
  }
  ll nAB = 0, nBC = 0, nCA = 0, nABC = 0;
  for(auto [_, v]: mpAB) nAB += (ll)v*(v-1)/2;
  for(auto [_, v]: mpBC) nBC += (ll)v*(v-1)/2;
  for(auto [_, v]: mpCA) nCA += (ll)v*(v-1)/2;
  for(auto [_, v]: mpABC) nABC += (ll)v*(v-1)/2;
  cout << (ll)n*(n+1)/2 - nAB - nBC - nCA + 2*nABC << endk;
  return 0;
}
