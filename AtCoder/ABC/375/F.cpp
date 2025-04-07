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
  int n, m, q; cin >> n >> m >> q;
  vector<int> A(m), B(m), C(m);
  rep(i, m) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--;
  }
  vector<int> T(q);
  vector<pair<int, int>> param(q);
  set<int> st;
  rep(i, q) {
    cin >> T[i];
    if(T[i] == 2) {
      cin >> param[i].first >> param[i].second;
      param[i].first--;
      param[i].second--;
    } else {
      cin >> param[i].first;
      param[i].first--;
      st.insert(param[i].first);
    }
  }
  vector<vector<ll>> dist(n, vector<ll>(n, longinf));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    if(!st.count(i)) {
      dist[A[i]][B[i]] = C[i];
      dist[B[i]][A[i]] = C[i];
    }
  }
  rep(k, n) rep(i, n) rep(j, n) {
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }
  vector<ll> ans;
  rrep(k, q) {
    if(T[k] == 1) {
      int id = param[k].first;
      int u = A[id], v = B[id];
      rep(i, n) rep(j, n) {
        chmin(dist[i][j], dist[i][u]+C[id]+dist[v][j]);
        chmin(dist[i][j], dist[i][v]+C[id]+dist[u][j]);
      }
    } else {
      ans.push_back(dist[param[k].first][param[k].second]);
    }
  }
  reverse(all(ans));
  for(ll a: ans) {
    cout << (a==longinf ? -1 : a) << endk;
  }
  return 0;
}
