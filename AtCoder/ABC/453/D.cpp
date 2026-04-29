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
  vector<string> S(h); rep(i, h) cin >> S[i];
  int s, g;
  vector<vector<int>> G(h*w*4);
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    if(S[i][j] == 'S') s = i*w+j;
    if(S[i][j] == 'G') g = i*w+j;
    rep(k, 4) {
      int pi = i - dx[k];
      int pj = j - dy[k];
      if(pi < 0 || pi >= h || pj < 0 || pj >= w) continue;
      if(S[pi][pj] == '#') continue;
      rep(l, 4) {
        if(S[i][j] == 'o' && l != k) continue;
        if(S[i][j] == 'x' && l == k) continue;
        int ni = i + dx[l];
        int nj = j + dy[l];
        if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if(S[ni][nj] == '#') continue;
        G[(i*w+j)*4+k].push_back((ni*w+nj)*4+l);
      }
    }
  }
  vector<int> dist(h*w*4, inf);
  vector<int> prev(h*w*4, -1);
  queue<int> que;
  rep(i, 4) {
    dist[s*4+i] = 0;
    que.push(s*4+i);
  }
  while(!que.empty()) {
    int v = que.front(); que.pop();
    for(int nv: G[v]) {
      if(dist[nv] > dist[v]+1 && dist[v]+1 <= 5000000) {
        dist[nv] = dist[v]+1;
        prev[nv] = v;
        que.push(nv);
      }
    }
  }
  rep(i, 4) {
    if(dist[g*4+i] != inf) {
      cout << "Yes" << endk;
      int tmp = g*4+i;
      vector<int> path;
      while(tmp != -1) {
        path.push_back(tmp);
        tmp = prev[tmp];
      }
      reverse(all(path));
      string ans;
      string dir = "DRUL";
      rep(i, path.size()) {
        if(i == 0) continue;
        ans += dir[path[i]%4];
      }
      cout << ans << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
