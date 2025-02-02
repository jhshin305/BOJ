#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

bool isNumber(string s) {
	if(s != "Fizz" && s != "Buzz" && s != "FizzBuzz") return true;
	return false;
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
	
	vector<string> s;
	bool check = true;
	for(int i = 0; i < 3; i++) {
		string temp;
		cin >> temp;
		if(check) s.push_back(temp);
		if(check && isNumber(temp)) check=false;
		#ifndef BOJ
		if(temp == "0") return 0;
		#endif
	}
	int ans = stoi(s.back()) + 4-s.size();
	if(ans%3==0 && ans%5==0) cout << "FizzBuzz" << endl;
	else if(ans%3==0) cout << "Fizz" << endl;
	else if(ans%5==0) cout << "Buzz" << endl;
	else cout << ans << endl;

	#ifndef BOJ
	}
	#endif
	
	return 0;
}