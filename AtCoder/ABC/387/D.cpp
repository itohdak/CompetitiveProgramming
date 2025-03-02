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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> dist;
vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
        par[ne] = cur;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<vector<edge>> G(h*w*2);
  int s, g;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    if(S[i][j] == 'S') {
      s = i*w+j;
    } else if(S[i][j] == 'G') {
      g = i*w+j;
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] != '#') {
        if(dx[k] == 0) {
          G[i*w+j].push_back({h*w+nx*w+ny, 1});
        } else {
          G[h*w+i*w+j].push_back({nx*w+ny, 1});
        }
      }
    }
  }
  ll ans = longinf;
  dijkstra(h*w*2, G, s);
  chmin(ans, min(dist[g], dist[h*w+g]));
  dijkstra(h*w*2, G, h*w+s);
  chmin(ans, min(dist[g], dist[h*w+g]));
  cout << (ans==longinf ? -1 : ans) << endk;
  return 0;
}
