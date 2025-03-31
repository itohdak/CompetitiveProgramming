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
  vector<int> A(7); rep(i, 7) cin >> A[i];
  map<int, int> mp;
  rep(i, 7) mp[A[i]]++;
  vector<int> cnt;
  for(auto [_, c]: mp) {
    cnt.push_back(c);
  }
  sort(all(cnt), greater<int>());
  if(cnt.size() < 2) {
    cout << "No" << endk;
  } else if(cnt[0] >= 3 && cnt[1] >= 2) {
    cout << "Yes" << endk;
  } else {
    cout << "No" << endk;
  }
  return 0;
}
