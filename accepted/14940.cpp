#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

bool isInside(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	#ifdef BOJ
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	#endif
	
	#ifndef BOJ
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);
	while(true) {
	#endif
	
	int n, m;
	cin >> n >> m;
	if(n == 0) return 0;
	vector<vector<int>> s(n, vector<int>(m));
	queue<pair<int, int>> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> s[i][j];
			if(s[i][j] == 1) s[i][j] = -1;
			else if(s[i][j] == 2) {
				q.push({i, j});
				s[i][j] = 0;
			}
		}
	}
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(isInside(x-1, y, n, m) && s[x-1][y] == -1) {
			s[x-1][y] = s[x][y] + 1;
			q.push({x-1, y});
		}
		if(isInside(x+1, y, n, m) && s[x+1][y] == -1) {
			s[x+1][y] = s[x][y] + 1;
			q.push({x+1, y});
		}
		if(isInside(x, y-1, n, m) && s[x][y-1] == -1) {
			s[x][y-1] = s[x][y] + 1;
			q.push({x, y-1});
		}
		if(isInside(x, y+1, n, m) && s[x][y+1] == -1) {
			s[x][y+1] = s[x][y] + 1;
			q.push({x, y+1});
		}
	}
	
	for(auto& i : s) {
		for(auto& j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	#ifndef BOJ
	}
	#endif
	
	return 0;
}