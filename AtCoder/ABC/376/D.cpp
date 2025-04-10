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
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
  }
  queue<int> q;
  vector<int> dist(n, inf);
  vector<bool> vis(n);
  int ans = inf;
  dist[0] = 0;
  q.push(0);
  while(q.size()) {
    int cur = q.front(); q.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    for(int ne: G[cur]) {
      if(ne == 0) {
        chmin(ans, dist[cur] + 1);
      }
      if(dist[ne] > dist[cur] + 1) {
        dist[ne] = dist[cur] + 1;
        q.push(ne);
      }
    }
  }
  cout << (ans==inf ? -1 : ans) << endk;
  return 0;
}
