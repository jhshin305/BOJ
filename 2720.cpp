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

	vector<int> units = {25, 10, 5, 1};
	
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		int c;
		cin >> c;
		for (auto const &unit : units) {
			cout << c/unit << " ";
			c %= unit;
		}
		cout << endl;
	}
	
	return 0;
}