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
  vector<int> H(n); rep(i, n) cin >> H[i];
  vector<int> L(q), R(q);
  rep(i, q) {
    cin >> L[i] >> R[i];
    L[i]--;
  }
  vector<int> id(q);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return L[i] > L[j];
  });
  int l = n-1;
  vector<int> ans(q);
  priority_queue<pair<int, int>> queue;
  fenwick_tree<int> bit(n);
  for(int i: id) {
    while(l > L[i]) {
      bit.add(l, 1);
      while(queue.size() && -queue.top().first < H[l]) {
        bit.add(queue.top().second, -1);
        queue.pop();
      }
      queue.push({-H[l], l});
      l--;
    }
    ans[i] = bit.sum(R[i], n);
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
