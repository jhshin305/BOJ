#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL); cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	bool check;
	if(n%2==0) {
		if(k%2 == 0 && n*n/2 <= k) check = true;
		else check = false;
	}
	else {
		if(n*n/2 <= k) check = true;
		else check = false;
	}
	if(check == true) {
		vector<vector<ll>> ans;
		if(n%2==0) {
			ll cnt = k-n*n/2;
			ll temp = cnt/2/(n*n);
			for(int i=0; i<n; i++) {
				ans.push_back({});
				for(int j=0; j<n; j++) {
					ans.back().push_back((i+j+1)%2+temp*2);
				}
			}
			cnt -= temp*2*(n*n);
			ll q = 0;
			if(cnt >= n*n) {
				for(int i=0; i<n; i++) {
					for(int j=0; j<n; j++) {
						ans[i][j] += 2*((i+j)%2);
					}
				}
				cnt -= n*n;
				q=1;
			}
			while(cnt) {
				for(int i=0; i<n; i++) {
					for(int j=0; j<n; j++) {
						ans[i][j] += 2*((i+j+q)%2);
						cnt -= 2*((i+j+q)%2);
						if(cnt == 0) break;
					}
					if(cnt == 0) break;
				}
				q+=1;
				q%=2;
			}
		}
		else {
			if(k%2 == 0) {
				ll cnt = k-n*n/2;
				ll temp = cnt/2/(n*n);
				for(int i=0; i<n; i++) {
					ans.push_back({});
					for(int j=0; j<n; j++) {
						ans.back().push_back((i+j)%2+temp*2);
					}
				}
				cnt -= temp*2*(n*n);
				ll q = 1;
				if(cnt >= n*n+1) {
					for(int i=0; i<n; i++) {
						for(int j=0; j<n; j++) {
							ans[i][j] += 2*((i+j+1)%2);
						}
					}
					cnt -= n*n+1;
					q=0;
				}
				while(cnt) {
					for(int i=0; i<n; i++) {
						for(int j=0; j<n; j++) {
							ans[i][j] += 2*((i+j+q)%2);
							cnt -= 2*((i+j+q)%2);
							if(cnt == 0) break;
						}
						if(cnt == 0) break;
					}
					q+=1;
					q%=2;
				}
			}
			else {
				ll cnt = k-n*n/2-1;
				ll temp = cnt/2/(n*n);
				for(int i=0; i<n; i++) {
					ans.push_back({});
					for(int j=0; j<n; j++) {
						ans.back().push_back((i+j+1)%2+temp*2);
					}
				}
				cnt -= temp*2*(n*n);
				ll q = 0;
				if(cnt >= n*n+1) {
					for(int i=0; i<n; i++) {
						for(int j=0; j<n; j++) {
							ans[i][j] += 2*((i+j)%2);
						}
					}
					cnt -= n*n-1;
					q=1;
				}
				while(cnt) {
					for(int i=0; i<n; i++) {
						for(int j=0; j<n; j++) {
							ans[i][j] += 2*((i+j+q)%2);
							cnt -= 2*((i+j+q)%2);
							if(cnt == 0) break;
						}
						if(cnt == 0) break;
					}
					q+=1;
					q%=2;
				}
			}
		}
		for (auto const &i : ans) {
			for (auto const &j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	else cout << -1 << endl;
	
	return 0;
}