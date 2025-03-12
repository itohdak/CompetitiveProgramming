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
  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, ll>>> G(n);
  priority_queue<
    pair<ll, pair<int, int>>,
    vector<pair<ll, pair<int, int>>>,
    greater<pair<ll, pair<int, int>>>
  > q;
  rep(i, m) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
    q.push({w, {u, v}});
  }
  vector<int> A(k), B(k);
  vector<int> cntA(n), cntB(n);
  rep(i, k) {
    cin >> A[i];
    A[i]--;
    cntA[A[i]]++;
  }
  rep(i, k) {
    cin >> B[i];
    B[i]--;
    cntB[B[i]]++;
  }
  set<int> st1(all(A)), st2(all(B));
  dsu uf(n);
  map<ll, pair<int, int>> mp;
  rep(i, n) {
    mp[i] = {cntA[i], cntB[i]};
  }
  ll ans = 0;
  while(q.size()) {
    auto [w, e] = q.top(); q.pop();
    auto [u, v] = e;
    if(uf.same(u, v)) continue;
    int l1 = uf.leader(u), l2 = uf.leader(v);
    auto [a1, b1] = mp[l1];
    auto [a2, b2] = mp[l2];
    mp.erase(l1);
    mp.erase(l2);
    uf.merge(u, v);
    int l3 = uf.leader(u);
    int a3 = a1+a2, b3 = b1+b2;
    int mn = min(a3, b3);
    if(mn > 0) {
      ans += w*mn;
      a3 -= mn;
      b3 -= mn;
    }
    mp[l3] = {a3, b3};
  }
  cout << ans << endk;
  return 0;
}
