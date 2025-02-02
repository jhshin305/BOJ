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
	
	int n, b;
	cin >> n >> b;
	string ans ="";
	while(n) {
		int temp = n%b;
		if(temp<=9) ans += temp+'0';
		else ans += temp+'A'-10;
		n /= b;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;	
	
	return 0;
}