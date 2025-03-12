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
  int h, w, d; cin >> h >> w >> d;
  vector<string> S(h); rep(i, h) cin >> S[i];
  int ans = 0;
  rep(i, h*w) REP(j, i+1, h*w) {
    int x1 = i/w, y1 = i%w;
    int x2 = j/w, y2 = j%w;
    if(S[x1][y1] == '#' || S[x2][y2] == '#') continue;
    int cnt = 0;
    rep(ii, h*w) {
      int x = ii/w, y = ii%w;
      if(S[x][y] == '#') continue;
      if(abs(x-x1)+abs(y-y1) <= d || abs(x-x2)+abs(y-y2) <= d) cnt++;
    }
    chmax(ans, cnt);
  }
  cout << ans << endk;
  return 0;
}
