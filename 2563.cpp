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

	vector<vector<int>> black(100, vector<int>(100));
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j=x; j<x+10; j++) {
			for (int k=y; k<y+10; k++) {
				black[j][k] = 1;
			}
		}
	}
	int ans = 0;
	for (auto const &i : black) {
		for (auto const &j : i) {
			ans += j;
		}
	}
	cout << ans << endl;
	
	
	#ifndef BOJ
	}
	#endif
	
	return 0;
}