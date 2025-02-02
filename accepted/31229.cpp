#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

#ifndef BOJ
#include <cstdio>
#endif

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	#ifndef BOJ
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);
	while(true) {
	#endif
	
	int n;
	cin >> n;
	#ifndef BOJ
	if(n==0) break;
	#endif

	vector<ll> primes;
	ll m = 2;
	while(primes.size()<n) {
		bool check = true;
		for (auto const &i : primes) {
			if(m%i == 0) {
				check = false;
				break;
			}
		}
		if(check) primes.push_back(m);
		m++;
	}

	for (auto const &i : primes) {
		cout << i << " ";
	}
	cout << endl;
	
	#ifndef BOJ
	}
	#endif
	
	return 0;
}