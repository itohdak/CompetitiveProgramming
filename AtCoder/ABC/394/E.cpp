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
  int n; cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<vector<pair<int, int>>> G(n*n+1);
  int s = n*n;
  map<char, vector<pair<int, int>>> mp;
  rep(i, n) {
    rep(j, n) {
      if(i == j) G[s].push_back({i*n+j, 0});
      if(S[i][j] != '-') {
        G[s].push_back({i*n+j, 1});
        mp[S[i][j]].push_back({i, j});
      }
    }
  }
  for(auto& [_, v]: mp) {
    for(auto& [f1, t1]: v) {
      for(auto& [f2, t2]: v) {
        G[t1*n+f2].push_back({f1*n+t2, 2});
      }
    }
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n*n+1, inf);
  vector<bool> vis(n*n+1);
  dist[s] = 0;
  pq.push({0, s});
  while(pq.size()) {
    auto [d, cur] = pq.top(); pq.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        pq.push({dist[ne], ne});
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      cout << (dist[i*n+j]==inf ? -1 : dist[i*n+j]) << ' ';
    }
    cout << endk;
  }
  return 0;
}
