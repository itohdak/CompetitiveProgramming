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
  int h, w; cin >> h >> w;
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  int a, b, c, d; cin >> a >> b >> c >> d;
  a--; b--; c--; d--;
  vector<int> dist(h*w, inf);
  vector<bool> vis(h*w, false);
  dist[a*w+b] = 0;
  deque<int> q;
  q.push_back(a*w+b);
  while(q.size()) {
    int cur = q.front(); q.pop_front();
    if(vis[cur]) continue;
    vis[cur] = true;
    int x = cur/w, y = cur%w;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    rep(k, 4) {
      bool ok = true;
      rep(l, 2) {
        int nx = x + dx[k]*(l+1), ny = y + dy[k]*(l+1);
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(S[nx][ny] == '#') ok = false;
        if(dist[nx*w+ny] > dist[cur] + !ok) {
          dist[nx*w+ny] = dist[cur] + !ok;
          if(ok) q.push_front(nx*w+ny);
          else q.push_back(nx*w+ny);
        }
      }
    }
  }
  cout << dist[c*w+d] << endk;
  return 0;
}
