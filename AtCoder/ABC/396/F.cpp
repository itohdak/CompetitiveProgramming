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

/* 転倒数 */
template< typename T >
struct BinaryIndexedTree {
  using U =
    typename std::conditional<std::is_same<T, long long>::value,
                              unsigned long long,
                              unsigned int>::type;

  BinaryIndexedTree(int sz) : _n(sz) {
    data.assign(++sz, 0);
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while(p <= _n) {
      data[p - 1] += U(x);
      p += p & -p;
    }
  }

private:
  vector< U > data;
  int _n;

  U sum(int r) {
    U ret = 0;
    while(r > 0) {
      ret += data[r - 1];
      r -= r & -r;
    }
    return ret;
  }
};
template< typename T >
ll inversion(const vector<T>& A) {
  int n = A.size();
  vector<int> id(n); rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    return A[i] > A[j];
  });
  BinaryIndexedTree<int> bit(n);
  ll sum = 0;
  // 要素の重複も考慮
  int l = 0;
  while(l < n) {
    int r = l;
    while(r < n && A[id[r]] == A[id[l]]) {
      sum += bit.sum(0, id[r]);
      r++;
    }
    for(int i=l; i<r; i++) bit.add(id[i], 1);
    l = r;
  }
  return sum;
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> B(m);
  rep(i, n) B[A[i]].push_back(i);
  ll inv = inversion(A);
  rep(i, m) {
    cout << inv << endk;
    ll l = 0;
    int sub = 0;
    rep(j, B[m-1-i].size()) {
      l += B[m-1-i][j]-sub;
      sub++;
    }
    sub = 0;
    ll r = 0;
    rrep(j, B[m-1-i].size()) {
      r += n-1-B[m-1-i][j]-sub;
      sub++;
    }
    inv += l-r;
  }
  return 0;
}
