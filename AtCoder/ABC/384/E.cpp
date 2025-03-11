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
  int h, w, X; cin >> h >> w >> X;
  int p, q; cin >> p >> q;
  p--; q--;
  vector<vector<ll>> S(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> S[i][j];
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  vector<vector<bool>> done(h, vector<bool>(w));
  Q.push({S[p][q], p*w+q});
  ll sz = 0;
  bool first = true;
  while(Q.size()) {
    auto [s, cur] = Q.top(); Q.pop();
    int x = cur/w, y = cur%w;
    if(done[x][y]) continue;
    done[x][y] = true;
    if(first || s < (sz+X-1)/X) {
      first = false;
      sz += s;
      int dx[4] = {0, -1, 0, 1};
      int dy[4] = {-1, 0, 1, 0};
      rep(k, 4) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(done[nx][ny]) continue;
        Q.push({S[nx][ny], nx*w+ny});
      }
    }
  }
  cout << sz << endk;
  return 0;
}
