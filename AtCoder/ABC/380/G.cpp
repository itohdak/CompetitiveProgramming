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

template<typename T>
ll inversion(const vector<T>& A) {
  int n = A.size();
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return (A[i] == A[j] ? i < j : A[i] > A[j]);
  });
  fenwick_tree<ll> bit(n);
  ll sum = 0;
  int l = 0;
  while(l < n) {
    int r = l;
    while(r < n && A[id[r]] == A[id[l]]) {
      sum += bit.sum(0, id[r]);
      r++;
    }
    REP(i, l, r) bit.add(id[i], 1);
    l = r;
  }
  return sum;
};

using mint = modint998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }

  // power of 2
  vector<mint> pw2(k+1);
  pw2[0] = 1;
  rep(i, k) pw2[i+1] = pw2[i] * 2;
  // factorial
  vector<mint> fact(k+1);
  fact[0] = 1;
  rep(i, k) fact[i+1] = fact[i] * (i+1);

  mint inv_all = inversion(P);
  vector<int> tmp(k);
  copy(begin(P), begin(P)+k, begin(tmp));
  mint inv_curr = inversion(tmp);
  mint inv_sum = (mint)k*(k-1)/2/2;
  
  mint ans = 0;
  fenwick_tree<int> bit(n);
  rep(i, k) bit.add(P[i], 1);
  rep(i, n-k+1) {
    mint tmp = inv_all - inv_curr + inv_sum;
    ans += tmp;
    if(i < n-k) {
      bit.add(P[i], -1);
      inv_curr -= bit.sum(0, P[i]);
      inv_curr += bit.sum(P[i+k]+1, n);
      bit.add(P[i+k], 1);
    }
  }
  ans /= (n-k+1);
  cout << ans.val() << endk;
  return 0;
}
