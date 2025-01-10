#include <bits/stdc++.h>
#define endl '\n'
#define mod %1000000007

#ifndef BOJ
#include <cstdio>
#endif

typedef long long ll;

using namespace std;

struct line {
	int to;
	ll cost;
	vector<int> route;
	line(int to, ll cost) : to(to), cost(cost), route({}) {}

	bool operator<(const line l) const {
		if(this->cost != l.cost) return this->cost > l.cost;
		else return this->to > l.to;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	#ifndef BOJ
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);
	while(true) {
	#endif
	
	int n, m, a, b;
	cin >> n;
	#ifndef BOJ
	if(n==0) break;
	#endif
	cin >> m >> a >> b;
	vector<line> lines;
	for (int i=0; i<m; i++) {
		int 
	}

	vector<int> ans;
	// dijkstra
	



	cout << ans.size() << endl;
	for (auto const &i : ans) {
		cout << i << " ";
	}
	
	#ifndef BOJ
	}
	#endif
	
	return 0;
}