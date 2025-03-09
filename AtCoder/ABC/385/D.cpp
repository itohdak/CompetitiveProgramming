#include <bits/stdc++.h>
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  sx--; sy--;
  vector<int> X(n), Y(n);
  rep(i, n) {
    cin >> X[i] >> Y[i];
    X[i]--; Y[i]--;
  }
  vector<char> D(m);
  vector<int> C(m);
  ll x = sx, y = sy;
  map<ll, vector<pair<ll, int>>> mpr, mpc;
  rep(i, n) {
    mpc[X[i]].push_back({Y[i], 2});
    mpr[Y[i]].push_back({X[i], 2});
  }
  rep(i, m) {
    cin >> D[i] >> C[i];
    ll nx, ny;
    if(D[i] == 'U') {
      nx = x, ny = y+C[i];
      mpc[x].push_back({y, 1});
      mpc[x].push_back({ny+1, -1});
    } else if(D[i] == 'D') {
      nx = x, ny = y-C[i];
      mpc[x].push_back({ny, 1});
      mpc[x].push_back({y+1, -1});
    } else if(D[i] == 'L') {
      nx = x-C[i], ny = y;
      mpr[y].push_back({nx, 1});
      mpr[y].push_back({x+1, -1});
    } else {
      nx = x+C[i], ny = y;
      mpr[y].push_back({x, 1});
      mpr[y].push_back({nx+1, -1});
    }
    x = nx, y = ny;
  }
  set<pair<int, int>> ans;
  for(auto& [y, v]: mpr) {
    sort(all(v));
    int tmp = 0;
    for(auto [x, t]: v) {
      if(t == 2) {
        if(tmp > 0) ans.insert({x, y});
      } else {
        tmp += t;
      }
    }
  }
  for(auto& [x, v]: mpc) {
    sort(all(v));
    int tmp = 0;
    for(auto [y, t]: v) {
      if(t == 2) {
        if(tmp > 0) ans.insert({x, y});
      } else {
        tmp += t;
      }
    }
  }
  cout << x+1 << ' ' << y+1 << ' ' << ans.size() << endk;
  return 0;
}
