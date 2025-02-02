#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

#ifndef BOJ
#include <cstdio>
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll large_mod_mul(ll a, ll b, ll m) {
	return ll((__int128)a*(__int128)b%m);
}

ll modpow(ll n, ll k, ll m) {
	ll ret = 1;
	n %= m;
	while (k) {
	if (k & 1) ret = large_mod_mul(ret, n, m);
	n = large_mod_mul(n, n, m);
	k /= 2;
	}
	return ret;
}


bool test_witness(ull a, ull n, ull s) {
	if (a >= n) a %= n;
	if (a <= 1) return true
	;
	ull d = n >> s;
	ull x = modpow(a, d, n);
	if (x == 1 || x == n-1) return true
	;
	while (s-- > 1) {
	x = large_mod_mul(x, x, n);
	if (x == 1) return false
	;
	if (x == n-1) return true
	;
	}
	return false;
}

bool is_prime(ull n) {
	if (n == 2) return true
	;
	if (n < 2 || n % 2 == 0) return false
	;
	ull d = n >> 1, s = 1;
	for(; (d&1) == 0; s++) d >>= 1;
	#define T(a) test_witness(a##ull, n, s)
		if (n < 4759123141ull) return T(2) && T(7) && T(61);
		return T(2) && T(325) && T(9375) && T(28178)
		&& T(450775) && T(9780504) && T(1795265022);
	#undef T
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}


ll pollard_rho(ll n) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <ll> dis(1, n - 1);
	ll x = dis(gen);
	ll y = x;
	ll c = dis(gen);
	ll g = 1;
	while (g == 1) {
	x = (large_mod_mul(x, x, n) + c) % n;
	y = (large_mod_mul(y, y, n) + c) % n;
	y = (large_mod_mul(y, y, n) + c) % n;
	g = gcd(abs(x - y), n);
	}
	return g;
}

void factorize(ll n, vector<ll>& fl) {
	if (n == 1) {
	return
	;
	}
	if (n % 2 == 0) {
	fl.push_back(2);
	factorize(n / 2, fl);
	}
	else if (is_prime(n)) {
	fl.push_back(n);
	}
	else
	{
	ll f = pollard_rho(n);
	factorize(f, fl);
	factorize(n / f, fl);
	}
}


int main() {	
	#ifndef BOJ
	while(true) {
	#endif
	vector<ll> fl;
	ll a;
	cin >> a;
	if(a==-1) break;
	factorize(a,fl);
	cout << fl.back() << endl;
	
	
	
	#ifndef BOJ
	}
	#endif
	
	return 0;
}