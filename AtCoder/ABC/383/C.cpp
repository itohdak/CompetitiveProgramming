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
  vector<int> D(h*w, inf);
  vector<int> vis(h*w);
  queue<int> q;
  rep(i, h) rep(j, w) {
    if(S[i][j] == 'H') {
      q.push(i*w+j);
      D[i*w+j] = 0;
    }
  }
  while(q.size()) {
    auto cur = q.front(); q.pop();
    int x = cur/w, y = cur%w;
    if(vis[cur]) continue;
    vis[cur] = true;
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    rep(k, 4) {
      int nx = x+dx[k], ny = y+dy[k];
      int ne = nx*w+ny;
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '.') {
        if(D[nx*w+ny] != inf) continue;
        if(D[cur]+1 > d) continue;
        if(vis[ne]) continue;
        D[ne] = D[cur]+1;
        q.push(ne);
      }
    }
  }
  int cnt = 0;
  rep(i, h) rep(j, w) if(D[i*w+j] != inf) cnt++;
  cout << cnt << endk;
  return 0;
}
