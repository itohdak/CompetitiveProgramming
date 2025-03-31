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
  vector<vector<int>> G(n);
  set<pair<int, int>> st;
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
    st.insert({min(u, v), max(u, v)});
  }
  vector<int> dist(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dist[ne] = dist[cur] + 1;
      dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  set<pair<int, int>> st2;
  rep(i, n) REP(j, i+1, n) {
    if(!st.count({i, j}) && abs(dist[i] - dist[j]) % 2 == 1) {
      st2.insert({i, j});
    }
  }
  int f = 0;
  if(st2.size() % 2 == 1) {
    cout << "First" << endl;
    f = 0;
  } else {
    cout << "Second" << endl;
    f = 1;
  }
  while(1) {
    if(f == 0) {
      auto [u, v] = *st2.begin();
      cout << u+1 << ' ' << v+1 << endl;
      st2.erase(st2.begin());
    } else {
      int u, v; cin >> u >> v;
      if(u == -1 && v == -1) {
        break;
      } else {
        u--; v--;
        st2.erase({min(u, v), max(u, v)});
      }
    }
    f = 1-f;
  }
  return 0;
}
