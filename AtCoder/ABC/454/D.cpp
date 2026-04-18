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
  int t; cin >> t;
  rep(i, t) {
    string a, b;
    cin >> a >> b;
    auto construct = [](string s) -> string {
      string ret;
      rep(i, s.size()) {
        if(s[i] == ')') {
          int sz = ret.size();
          if(sz >= 3 && ret[sz-1] == 'x' && ret[sz-2] == 'x' && ret[sz-3] == '(') {
            ret.pop_back();
            ret.pop_back();
            ret.pop_back();
            ret.push_back('x');
            ret.push_back('x');
          } else {
            ret.push_back(s[i]);
          }
        } else {
          ret.push_back(s[i]);
        }
      }
      return ret;
    };
    string a_ = construct(a);
    string b_ = construct(b);
    cout << (a_ == b_ ? "Yes" : "No") << endk;
  }
  return 0;
}
