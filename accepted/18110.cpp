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
	vector<double> v(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end());
	v = vector<double>(v.begin() + round(n*0.15), v.end() - round(n*0.15));
	cout << (n==0 ? 0 : round(accumulate(v.begin(), v.end(), .0) / v.size())) << endl;
	
	return 0;
}