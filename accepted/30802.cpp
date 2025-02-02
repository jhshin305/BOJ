#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

int main() {
	#ifdef BOJ
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	#endif
	
	int n;
	cin >> n;
	vector<int> s(6);
	for (auto &i : s) cin >> i;
	int t, p;
	cin >> t >> p;

	int anst = 0;
	int ansp = 0;

	for (auto const &i : s) {
		anst += (i+t-1)/t;
	}

	cout << anst << endl << n/p << " " << n%p << endl;
	
	
	return 0;
}