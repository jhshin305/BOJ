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
	
	#ifndef BOJ
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);
	while(true) {
	#endif
	
	int n;
	cin >> n;
	#ifndef BOJ
	if(n == 0) return 0;
	#endif
	int m;
	cin >> m;
	string s;
	cin >> s;
	int ans = 0;
	int l = 0;
	for(auto& i : s) {
		if(i == (l%2==0 ? 'I' : 'O')) l++;
		else {
			int le = l-(l+1)%2-n*2-1;
			if(le >= 0) ans += (le+1)/2+1;
			l = 0;
		}
	}
	int le = l-(l+1)%2-n*2-1;
	if(le >= 0) ans += (le+1)/2+1;
	cout << ans << endl;
	
	#ifndef BOJ
	}
	#endif
	
	return 0;
}