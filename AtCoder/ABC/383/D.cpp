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

vector<ll> Eratosthenes(int N) {
  bool arr[2000001];
  vector<ll> primes;
  for(int i=0; i<=N; i++) {
    arr[i] = true;
  }
  for(int i=2; i<=N; i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<=N; j++) {
        arr[i*(j+2)] = false;
      }
    }
  }
  for(int i=2; i<=N; i++) {
    if(arr[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  vector<ll> primes = Eratosthenes(2000000);
  int ans = 0;
  for(ll p: primes) {
    ll tmp = 1;
    rep(i, 8) {
      if(tmp*p > n) {
        tmp = longinf;
        break;
      }
      tmp *= p;
    }
    if(tmp <= n) {
      ans++;
    } else {
      break;
    }
  }
  vector<ll> pw(primes.size());
  copy(all(primes), begin(pw));
  for(ll& p: pw) {
    p = p*p;
  }
  rep(i, pw.size()) {
    if(pw[i] > n/pw[i]) break;
    int cnt = upper_bound(all(pw), n/pw[i]) - begin(pw) - i - 1;
    ans += cnt;
  }
  cout << ans << endk;
  return 0;
}
