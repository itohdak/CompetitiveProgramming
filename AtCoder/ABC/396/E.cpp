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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> X(m), Y(m), Z(m);
  rep(i, m) {
    cin >> X[i] >> Y[i] >> Z[i];
    X[i]--; Y[i]--;
  }
  vector<ll> ans(n);
  for(int d=0, j=1; j<=1000000000; d++, j<<=1) {
    vector<vector<pair<int, int>>> G(n);
    rep(i, m) {
      int f = (Z[i]>>d)&1;
      G[X[i]].push_back({Y[i], f});
      G[Y[i]].push_back({X[i], f});
    }
    vector<int> val(n, -1);
    bool ok = true;
    dsu uf(n);
    auto dfs = [&](auto dfs, int cur) -> void {
      for(auto [ne, f]: G[cur]) {
        if(val[ne] != -1) {
          if(val[cur]^f != val[ne]) {
            ok = false;
          }
          continue;
        }
        val[ne] = val[cur]^f;
        uf.merge(cur, ne);
        dfs(dfs, ne);
      }
    };
    rep(i, n) {
      if(val[i] == -1) {
        val[i] = 0;
        dfs(dfs, i);
      }
    }
    if(!ok) {
      cout << -1 << endk;
      return 0;
    }
    map<int, vector<int>> mp;
    rep(i, n) {
      mp[uf.leader(i)].push_back(i);
    }
    int cum = 0;
    for(auto [_, v]: mp) {
      int sz = v.size();
      int sum = 0;
      for(int cur: v) {
        sum += val[cur];
      }
      if(sum*2 > sz) {
        for(int cur: v) {
          if(!val[cur]) ans[cur] += j;
        }
      } else {
        for(int cur: v) {
          if(val[cur]) ans[cur] += j;
        }
      }
    }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
