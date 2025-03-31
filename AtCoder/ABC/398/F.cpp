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

void Manacher(string S, vector<int>& res) {
  int i=0, j=0;
  while(i < S.size()) {
    while(i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
    res[i] = j;
    int k=1;
    while(i-k >= 0 && i+k < S.size() && k+res[i-k] < j) res[i+k] = res[i-k], ++k;
    i += k; j -= k;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  vector<int> res(n);
  Manacher(s, res);
  string ans(2*n+1, ' ');
  rep(i, n) {
    if(n-i == res[i]) {
      string t1 = s.substr(0, i);
      string t2 = t1;
      reverse(all(t2));
      ans = t1 + s[i] + t2;
      break;
    }
  }
  {
    string t(2*n-1, 'x');
    rep(i, n) t[i*2] = s[i];
    int m = 2*n-1;
    vector<int> res(m);
    Manacher(t, res);
    string ans2(2*m+1, ' ');
    rep(i, m) {
      if(m-i == res[i]) {
        string t1 = t.substr(0, i);
        string t2 = t1;
        reverse(all(t2));
        ans2 = t1 + t[i] + t2;
        string tmp;
        for(char c: ans2) {
          if(c != 'x') tmp += c;
        }
        if(tmp.size() < ans.size()) {
          ans = tmp;
        }
        break;
      }
    }
  }
  cout << ans << endk;
  return 0;
}
