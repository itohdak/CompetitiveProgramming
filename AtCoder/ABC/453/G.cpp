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

template <typename S2, typename Op, typename E>
struct LambdaMonoid {
  using S = S2;
  S op(const S& a, const S& b) const { return _op(a, b); }

  S e() const { return _e(); }

  LambdaMonoid(Op _op, E _e) : _op(_op), _e(_e) {}

 private:
  Op _op;

  E _e;
};

template <typename Op, typename E>
LambdaMonoid(Op _op, E _e) -> LambdaMonoid<decltype(_e()), Op, E>;

template <typename Monoid>
struct PersistentSegmentTree {
  using S = typename Monoid::S;
  struct Node {
    S d;
    Node *l, *r;
  };
  using NP = Node*;

 private:
  int n{};
  Monoid m;

  NP merge(NP l, NP r) const { return new Node{m.op(l->d, r->d), l, r}; }

  NP build(int l, int r, const vector<S>& v) const {
    if (l + 1 == r) return new Node{v[l], nullptr, nullptr};
    NP lp = build(l, (l + r) / 2, v);
    NP rp = build((l + r) / 2, r, v);
    return merge(lp, rp);
  }

  NP set(int a, const S& x, NP k, int l, int r) const {
    if (r <= a || a + 1 <= l) {
      return k;
    } else if (a <= l && r <= a + 1) {
      return new Node{x, nullptr, nullptr};
    } else {
      return merge(set(a, x, k->l, l, (l + r) >> 1),
                   set(a, x, k->r, (l + r) >> 1, r));
    }
  }

  NP apply(int a, const S& x, NP k, int l, int r) const {
    if (r <= a || a + 1 <= l) {
      return k;
    } else if (a <= l && r <= a + 1) {
      return new Node{m.op(k->d, x), nullptr, nullptr};
    } else {
      return merge(apply(a, x, k->l, l, (l + r) >> 1),
                   apply(a, x, k->r, (l + r) >> 1, r));
    }
  }

  S prod(int a, int b, NP k, int l, int r) const {
    if (r <= a || b <= l) {
      return m.e();
    } else if (a <= l && r <= b) {
      return k->d;
    } else {
      return m.op(prod(a, b, k->l, l, (l + r) >> 1),
                  prod(a, b, k->r, (l + r) >> 1, r));
    }
  }

 public:
  PersistentSegmentTree() = default;

  explicit PersistentSegmentTree(Monoid m, int n) : m(m), n(n) {}

  NP build(const vector<S>& v) const {
    assert(n == (int)v.size());
    return build(0, n, v);
  }

  NP set(NP t, int k, const S& x) const { return set(k, x, t, 0, n); }

  S get(NP t, int k) const {
    int l = 0, r = n;
    while (l + 1 < r) {
      int p = (l + r) / 2;
      if (k < p) {
        t = t->l;
        r = p;
      } else {
        t = t->r;
        l = p;
      }
    }
    return t->d;
  }

  NP apply(NP t, int k, const S& x) const { return apply(k, x, t, 0, n); }

  S prod(NP t, int a, int b) const { return prod(a, b, t, 0, n); }

  S all_prod(NP t) const { return t->d; }
};

struct RangeSum {
  using S = ll;
  S op(const S& a, const S& b) const { return a + b; }
  S e() const { return 0LL; }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  PersistentSegmentTree psegtree(RangeSum(), m);
  vector<ll> ini(m, 0);
  auto iseg = psegtree.build(ini);
  vector<decltype(psegtree)::NP> root(n, iseg);
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      x--; y--;
      root[x] = root[y];
    } else if(t == 2) {
      int x, y, z; cin >> x >> y >> z;
      x--; y--;
      root[x] = psegtree.set(root[x], y, z);
    } else {
      int x, l, r; cin >> x >> l >> r;
      x--; l--;
      cout << psegtree.prod(root[x], l, r) << endk;
    }
  }
  return 0;
}
