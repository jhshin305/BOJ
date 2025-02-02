#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	vector<vector<ll>> ans;
	ans.push_back({3,4});

	while (testcase--)
	{
		int n;
		cin >> n;

		while (ans.size() < n)
		{
			ans.push_back({
				(ans.back()[0]*3+ans.back()[1])mod,
				(ans.back()[0]*4+ans.back()[1]*2)mod
			});
		}
		cout << (ans[n-1][0]+ans[n-1][1])mod << endl;
	}

	return 0;
}