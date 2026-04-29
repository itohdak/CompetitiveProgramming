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
struct S {
  int n;
  mint sum, sum2;
};
S op(S a, S b) {
  return {a.n+b.n, a.sum+b.sum, a.sum2+b.sum2};
}
S e() {
  return {1, 0, 0};
}
struct F {
  mint a;
};
S mapping(F f, S x) {
  return {x.n, x.sum + x.n*f.a, x.sum2 + 2*f.a*x.sum + x.n*f.a*f.a};
}
F composition(F f, F g) {
  return {f.a + g.a};
}
F id() {
  return {0};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, q) {
    int l, r, a; cin >> l >> r >> a;
    l--;
    seg.apply(l, r, {a});
    auto ret = seg.prod(l, r);
    cout << ((ret.sum*ret.sum - ret.sum2) / 2).val() << endk;
  }
  return 0;
}
