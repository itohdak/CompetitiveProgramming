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
  string s; cin >> s;
  stack<int> q;
  bool ok = true;
  for(char c: s) {
    switch(c) {
      case '(':
      q.push(0);
        break;
      case '<':
      q.push(1);
        break;
      case '[':
        q.push(2);
        break;
      case ')':
        if(q.size()) {
          if(q.top() == 0) {
            q.pop();
          } else {
            ok = false;
          }
        } else {
          ok = false;
        }
        break;
      case '>':
        if(q.size()) {
          if(q.top() == 1) {
            q.pop();
          } else {
            ok = false;
          }
        } else {
          ok = false;
        }
        break;
      case ']':
        if(q.size()) {
          if(q.top() == 2) {
            q.pop();
          } else {
            ok = false;
          }
        } else {
          ok = false;
        }
        break;
      default:
        break;
    }
  }if(q.size()) {
    ok = false;
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
