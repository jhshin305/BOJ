#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);
	
	while(true) {/////////////////////////
	int n;
	cin >> n;
	if(n==0) break;//////////////////////////
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<ll> ans(n+1);
	ans[0] = 1;
	for (int i=0; i<n; i++) {
		if(i+a[i] < n) ans[i+a[i]+1] = (ans[i+a[i]+1] + ans[i])mod;
		if((i-a[i] >= 0) && (a[i] != a[i-a[i]])) ans[i+1] = (ans[i+1] + ans[i-a[i]])mod;
	}
	cout << ans.back() << endl;
	}////////////////////////
	return 0;
}