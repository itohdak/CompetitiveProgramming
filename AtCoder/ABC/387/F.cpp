#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using mint = modint998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n);
  vector<vector<int>> G(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
    G[i].push_back(A[i]);
  }
  dsu uf(n);
  vector<bool> seen(n), finished(n);
  vector<int> path;
  vector<bool> in_loop(n);
  auto dfs = [&](auto dfs, int cur) {
    if(seen[cur]) {
      if(finished[cur]) return;
      // loop
      for(auto itr=find(all(path), cur); itr!=end(path); itr++) {
        uf.merge(*itr, cur);
        in_loop[*itr] = true;
      }
      return;
    }
    seen[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      dfs(dfs, ne);
    }
    finished[cur] = true;
  };
  rep(i, n) {
    path.clear();
    dfs(dfs, i);
  }
  vector<vector<pair<int, int>>> G2(n);
  rep(cur, n) {
    for(int ne: G[cur]) {
      if(!(in_loop[cur] && in_loop[ne])) {
        G2[cur].push_back({ne, 1});
        G2[ne].push_back({cur, -1});
      }
    }
  }
  vector<vector<mint>> dp(n, vector<mint>(m, 1));
  vector<vector<mint>> suml(n, vector<mint>(m+1)), sumr(n, vector<mint>(m+1));
  auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
    for(auto& [ne, t]: G2[cur]) {
      if(ne == par) continue;
      dfs2(dfs2, ne, cur);
      rep(i, m) {
        if(t == 1) {
          dp[cur][i] *= suml[ne][i+1];
        } else {
          dp[cur][i] *= sumr[ne][i];
        }
      }
    }
    rep(i, m) {
      suml[cur][i+1] = suml[cur][i] + dp[cur][i];
    }
    rrep(i, m) {
      sumr[cur][i] = sumr[cur][i+1] + dp[cur][i];
    }
  };
  map<int, vector<mint>> mp;
  rep(root, n) {
    if(!in_loop[root]) continue;
    int leader = uf.leader(root);
    if(!mp.count(leader)) {
      mp[leader] = vector<mint>(m, 1);
    }
    dfs2(dfs2, root, -1);
    rep(i, m) {
      mp[leader][i] *= dp[root][i];
    }
  }
  mint ans = 1;
  for(auto& [root, v]: mp) {
    ans *= accumulate(all(v), (mint)0);
  }
  cout << ans.val() << endk;
  return 0;
}
