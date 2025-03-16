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
  int n, q; cin >> n >> q;
  dsu uf(n);
  map<int, int> color;
  vector<int> cnt(n, 1);
  map<int, pair<int, int>> range;
  rep(i, n) {
    color[i] = i;
    range[i] = {i, i+1};
  }
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, c; cin >> x >> c;
      x--; c--;
      auto [l, r] = range[uf.leader(x)];
      cnt[color[uf.leader(x)]] -= (r-l);
      color.erase(uf.leader(x));
      range.erase(uf.leader(x));
      if(l-1 >= 0 && color[uf.leader(l-1)] == c) {
        auto [l1, r1] = range[uf.leader(l-1)];
        cnt[color[uf.leader(l-1)]] -= (r1-l1);
        color.erase(uf.leader(l-1));
        range.erase(uf.leader(l-1));
        uf.merge(uf.leader(x), uf.leader(l-1));
        l = l1;
      }
      if(r < n && color[uf.leader(r)] == c) {
        auto [l2, r2] = range[uf.leader(r)];
        cnt[color[uf.leader(r)]] -= (r2-l2);
        color.erase(uf.leader(r));
        range.erase(uf.leader(r));
        uf.merge(uf.leader(x), uf.leader(r));
        r = r2;
      }
      color[uf.leader(x)] = c;
      range[uf.leader(x)] = {l, r};
      cnt[color[uf.leader(x)]] += (r-l);
    } else {
      int c; cin >> c;
      c--;
      cout << cnt[c] << endk;
    }
  }
  return 0;
}
