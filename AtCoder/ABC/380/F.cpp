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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, l; cin >> n >> m >> l;
  vector<pair<int, int>> status(n+m+l);
  rep(i, n+m+l) {
    int a; cin >> a;
    status[i] = {(i<n ? 0 : (i<n+m ? 1 : 2)), a};
  }
  vector<int> pw3(n+m+l+1);
  pw3[0] = 1;
  rep(i, n+m+l+1) {
    if(i) {
      pw3[i] = pw3[i-1]*3;
    }
  }
  vector<vector<int>> win(2, vector<int>(pw3[n+m+l], -1));
  int stats = 0;
  rep(i, n+m+l)   {
    stats += status[i].first * pw3[i];
  }
  auto dfs = [&](auto dfs, int f) -> int {
    if(win[f][stats] != -1) {
      return win[f][stats];
    }
    bool can_win = false;
    bool ok = false;
    rep(i, n+m+l) {
      if(status[i].first == f) {
        ok = true;
        // don't swap
        stats -= status[i].first * pw3[i];
        status[i].first = 2;
        stats += status[i].first * pw3[i];
        dfs(dfs, 1-f);
        can_win |= (win[1-f][stats] == f);
        stats -= status[i].first * pw3[i];
        status[i].first = f;
        stats += status[i].first * pw3[i];
        rep(j, n+m+l) {
          if(status[i].second > status[j].second && status[j].first == 2) {
            // swap
            stats -= status[i].first * pw3[i];
            stats -= status[j].first * pw3[j];
            swap(status[i].first, status[j].first);
            stats += status[i].first * pw3[i];
            stats += status[j].first * pw3[j];
            dfs(dfs, 1-f);
            can_win |= (win[1-f][stats] == f);
            stats -= status[i].first * pw3[i];
            stats -= status[j].first * pw3[j];
            swap(status[i].first, status[j].first);
            stats += status[i].first * pw3[i];
            stats += status[j].first * pw3[j];
          }
        }
      }
    }
    if(!ok) {
      win[f][stats] = 1-f;
    } else {
      win[f][stats] = (can_win ? f : 1-f);
    }
    return win[f][stats];
  };
  dfs(dfs, 0);
  cout << (win[0][stats] == 0 ? "Takahashi" : "Aoki") << endk;
  return 0;
}
