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
  string s; cin >> s;
  vector<vector<int>> cnt(2, vector<int>(n+1));
  fenwick_tree<int> bit(n);
  rep(i, n) {
    rep(j, 2) {
      cnt[j][i+1] = cnt[j][i] + (s[i] == char('1'+j));
    }
    if(s[i] == '/') bit.add(i, 1);
  }
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    auto test = [&](int k) -> bool {
      int lb = lower_bound(all(cnt[0]), cnt[0][l]+k) - begin(cnt[0]);
      int ub = upper_bound(all(cnt[1]), cnt[1][r]-k) - begin(cnt[1]);
      if(lb >= ub) return false;
      return bit.sum(lb, ub) > 0;
    };
    int ok = 0, ng = n/2+1;
    while(ng-ok > 1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    if(ok == 0) {
      cout << (bit.sum(l, r) > 0) << endk;
    } else {
      cout << ok*2+1 << endk;
    }
  }
  return 0;
}
