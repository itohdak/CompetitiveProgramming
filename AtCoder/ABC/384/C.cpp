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
  vector<int> A(5); rep(i, 5) cin >> A[i];
  vector<pair<int, string>> S;
  rep(i, 1<<5) {
    if(i == 0) continue;
    int score = 0;
    string name;
    rep(j, 5) {
      if((i>>j)&1) {
        score += A[j];
        name += char('A'+j);
      }
    }
    S.push_back({score, name});
  }
  sort(all(S), [&](pair<int, string> s1, pair<int, string> s2) {
    if(s1.first == s2.first) {
      return s1.second < s2.second;
    } else {
      return s1.first > s2.first;
    }
  });
  for(auto [_, name]: S) {
    cout << name << endk;
  }
  return 0;
}
