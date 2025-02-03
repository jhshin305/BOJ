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
	bool check = false;
	vector<ll> a(n);
	for (auto  &i : a) {
		cin >> i;
	}
	for (int i=0; i<n; i++) {
		ll temp = a[i];
		ll m = (n+i-temp)%k;
		ll o = n%k;
		ll tm = m;
		ll to = o;
		ll tk = k;
		while(tm!=m || to!=o || tm!=m) {
			tm = m;
			to = o;
			tk = k;

			m %= k;
			o %= k;
			m %= o;
			k %= o;
		}
		check = false;
		for(int j=0; j<k; j++) {
			if((o*j+m)%k == 0) {
				check = true;
				break;
			}
			if(j!=0 && (o*j)%k==0) break;
		}
		if(check == false) break;
	}
	cout << (check ? "YES" : "NO") << endl;
	
	return 0;
}