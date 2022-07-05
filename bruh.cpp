// why are you even seeing this code. clearly this is garbage ┐(‘～`；)┌

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define forn(i,n) for(int i = 0; i < n; ++i)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define ln "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long

/*--------------------------------------------------------------------------------------------------------------------*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (a == 0) return b; else return gcd (b % a, a);}
/*--------------------------------------------------------------------------------------------------------------------*/

// (づ｡◕‿‿◕｡)づ you got this

//  need to get smarter at all costs

template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo(){       // default constructor
        fac[0] = ifac[0] = 1;
        for(ll i = 1; i <= SZ; i++) {
            fac[i] = mod_mul(i, fac[i - 1], MOD);
            ifac[i] = inv(fac[i]);
        }
    }
    
    ll po (ll b, ll p) {    // i have no idea wtf this is --> looks like it is expo function
        return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
    }
    
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b) return 0;
        ll tmp = mod_mul(fac[a], ifac[b], MOD);
        tmp = mod_mul(tmp, ifac[a - b], MOD);
        return tmp;
    }
    
};

// credits for this snippet: BenQ
// submission using this: https://codeforces.com/contest/893/submission/162699520

Combo<200010> C;

void solve() {
    int n; cin >> n;
    cout << mod_sub(mod_mul(2, C.comb((2 * n) - 1, n), MOD), n, MOD) << ln;
}

signed main() {
    fastio();
    int it; it = 1;
    forn(_it,it) solve();
}

