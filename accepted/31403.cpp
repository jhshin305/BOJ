#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
	cout << a+b-c << endl;
	string A = to_string(a);
	string B = to_string(b);
	int d = stoi(A+B);
	cout << d-c << endl;
	
	return 0;
}