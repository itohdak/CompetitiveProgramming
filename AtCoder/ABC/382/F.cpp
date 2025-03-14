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

int op(int a, int b) {
  return min(a, b);
}
int e() {
  return inf;
}
int mapping(int f, int a) {
  return min(f, a);
}
int composition(int f, int g) {
  return min(f, g);
}
int id() {
  return inf;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w, n; cin >> h >> w >> n;
  vector<int> R(n), C(n), L(n);
  rep(i, n) {
    cin >> R[i] >> C[i] >> L[i];
    R[i]--; C[i]--;
  }
  vector<int> ids(n);
  iota(all(ids), 0);
  sort(all(ids), [&](int i, int j) {
    if(R[i] == R[j]) return i < j;
    else return R[i] > R[j];
  });
  vector<int> init(w, h);
  lazy_segtree<int, op, e, int, mapping, composition, id> seg(init);
  vector<int> ans(n);
  for(int i: ids) {
    int mn = seg.prod(C[i], C[i]+L[i]);
    ans[i] = mn-1;
    seg.apply(C[i], C[i]+L[i], ans[i]);
  }
  rep(i, n) cout << ans[i]+1 << endk;
  return 0;
}
