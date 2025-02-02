#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);////////////////////
	
	while(true) {////////////////////
	int m, n;
	cin >> m >> n;
	vector<int> x(m-1);
	vector<int> y(n-1);
	for (auto &i : x) cin >> i;
	for (auto &i : y) cin >> i;
	sort(x.begin(), x.end(), greater<>());
	sort(y.begin(), y.end(), greater<>());

	int idx_x = 0;
	int idx_y = 0;
	int ans = 0;
	
	while(idx_x!=m-1 || idx_y!=n-1) {
		if(idx_x>=m-1) ans += y[idx_y++]*(idx_x+1);
		else if(idx_y>=n-1) ans += x[idx_x++]*(idx_y+1);
		else if(x[idx_x] > y[idx_y]) ans += x[idx_x++]*(idx_y+1);
		else ans += y[idx_y++]*(idx_x+1);
	}
	cout << ans << endl;
	}////////////////////
	
	return 0;
}