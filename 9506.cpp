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
	#endif
	
	while(true) {
		int n;
		cin >> n;
		if(n==-1) break;
		vector<int> factors;
		for (int i=1; i<n; i++) {
			if(n%i==0) factors.push_back(i);
		}
		if(n==accumulate(factors.begin(), factors.end(), 0)) {
			cout << n << " = ";
			for (int i=0; i<factors.size(); i++) {
				if(i!=0) cout << " + ";
				cout << factors[i];
			}
			cout << endl;
		}
		else cout << n << " is NOT perfect." << endl;
	}
	
	return 0;
}