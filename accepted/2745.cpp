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
	
	string s;
	cin >> s;
	#ifndef BOJ
	if(s=="0") break;
	#endif
	int b;
	cin >> b;
	int d = 1;
	int ans = 0;
	reverse(s.begin(), s.end());
	for (auto const &i : s) {
		if('0'<=i && i<='9') ans += (i-'0')*d;
		else ans += (i-'A'+10)*d;
		d *= b;
	}
	cout << ans << endl;
	
	
	#ifndef BOJ
	}
	#endif
	
	return 0;
}