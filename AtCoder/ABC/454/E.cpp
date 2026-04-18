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

string sol(int n, int a, int b) {
  string s;
  for(int i=0; i<b; i++) {
    s += string(n-1, (i&1 ? 'U' : 'D'));
    if(i < n-1) s += 'R';
  }

  if(b&1) {
    for(int j=n-1; j>a; j--) {
      s += ((b+j)&1 ? 'L' : 'R');
      if(j) s += (b&1 ? 'U' : 'D');
    }
    if(a) s += 'U';
    for(int j=a-1; j>=0; j--) {
      s += ((b+j)&1 ? 'R' : 'L');
      if(j) s += (b&1 ? 'U' : 'D');
    }
    s += 'R';
  } else {
    for(int j=0; j<a; j++) {
      s += ((b+j)&1 ? 'L' : 'R');
      if(j < n-1) s += 'D';
    }
    if(a < n-1) s += 'D';
    for(int j=a+1; j<n; j++) {
      s += ((b+j)&1 ? 'R' : 'L');
      if(j < n-1) s += 'D';
    }
    if(b+1 < n-1) s += 'R';
  }

  for(int i=b+2; i<n; i++) {
    s += string(n-1, (i&1 ? 'D' : 'U'));
    if(i < n-1) s += 'R';
  }

  return s;
}
void solve() {
  int n; cin >> n;
  int a, b; cin >> a >> b;
  a--; b--;
  if(n&1) {
    cout << "No" << endk;
    return;
  }
  if((a&1) == (b&1)) {
    cout << "No" << endk;
    return;
  }
  cout << "Yes" << endk;
  string s;
  if(b < n-1) {
    s = sol(n, a, b);
  } else {
    s = sol(n, n-1-a, n-1-b);
    reverse(all(s));
  }
  cout << s << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
