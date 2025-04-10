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
  int n; cin >> n;
  string s, t; cin >> s >> t;
  if(s == t) {
    cout << 0 << endk;
    return 0;
  }
  int c = 26;
  vector<int> to(c, -1);
  bool ok = true;
  rep(i, n) {
    int u = s[i]-'a', v = t[i]-'a';
    if(to[u] != -1 && to[u] != v) {
      ok = false;
    }
    to[u] = v;
  }
  if(!ok) {
    cout << -1 << endk;
    return 0;
  }
  auto tmp = to;
  sort(all(tmp));
  ok = false;
  rep(i, c) {
    if(i != tmp[i]) ok = true;
  }
  if(!ok) {
    cout << -1 << endk;
    return 0;
  }
  dsu uf(c);
  vector<int> in_deg(c);
  int ans = 0;
  rep(i, c) {
    if(to[i] != -1) {
      if(to[i] != i) {
        ans++;
      }
      in_deg[to[i]]++;
      uf.merge(i, to[i]);
    }
  }
  for(const auto &v: uf.groups()) {
    bool cycle = true;
    for(int i: v) {
      if(in_deg[i] != 1) cycle = false;
    }
    if(cycle && v.size() > 1) {
      ans++;
    }
  }
  cout << ans << endk;
  return 0;
}
