#include <bits/stdc++.h>
#define endl '\n'
#define mod % 1000000007

typedef long long ll;

using namespace std;

struct trie {
	bool last=false;
	map<char, trie*> node;

	void insert(string s);
	int find(string s);
};

void trie::insert(string s) {
	trie* curr = this;
	for (auto const &c : s) {
		if(curr->node.find(c) == curr->node.end()) {
			curr->node.insert({c, new trie()});
		}
		curr = curr->node[c];
	}
	curr->last = true;
}

int trie::find(string s) {
	trie* curr = this;
	for (int i=0; i<s.size(); i++) {
		if(curr->node.find(s[i]) == curr->node.end()) {
			return 0;
		}
		curr = curr->node[s[i]];
	}
	return curr->last ? 1 : 2;
}

vector<string> split(string s) {
	vector<string> result;
	string temp;
	for (auto const &i : s) {
		if(i == ' ') {
			if(temp.empty() == false) {
				result.push_back(temp);
				temp.clear();
			}
		}
		else temp += i;
	}
	if(temp.empty() == false) result.push_back(temp);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("C:/Users/jhshin/Desktop/secret/BOJ/input.txt", "r", stdin);//////////
	while(true){////////////////
	int s;
	cin >> s;
	if(s==0) break;////////////////////

	trie syllable;
	for (int i=0; i<s; i++) {
		string temp;
		cin >> temp;
		syllable.insert(temp);
	}
	bool check = true;

	cin.ignore();
	for (int i=0; i<3; i++) {
		int l = 0;
		string s;
		getline(cin, s);

		// spelling, very, hard
		vector<string> sp = split(s);
		// spelling
		vector<vector<int>> cnts;

		for (auto const &j : sp) { // spelling
			int pos = 0;
			int len = 1;

			vector<set<int>> cnt(j.size()+1);
			cnt[pos].insert(1);

			while(pos+len <= j.size()) {
				while (cnt[pos].size()!=0 && (pos+len <= j.size() && syllable.find(j.substr(pos, len)))) {
					// cout << pos << " " << len << " " << j.substr(pos, len) << endl;
					if(syllable.find(j.substr(pos, len)) == 1) {
						for (auto const &k : cnt[pos]) {
							cnt[pos+len].insert(k+1);
						}
					}
					len++;
				}
				pos++;
				len = 1;
				l++;
			}

			cnts.push_back({});
			for (auto const &k : cnt.back()) {
				cnts.back().push_back(k-1);
			}
		}


		// check haiku
		check = false;
		for (int j=1; j<cnts.size(); j++) {
			vector<int> temp = cnts[j];
			cnts[j] = {};
			for (auto const &k : temp) {
				for (auto const &l : cnts[j-1]) {
					cnts[j].push_back(k+l);
				}
			}
		}
		for (auto const &k : cnts.back()) {
			if(k == 5 + (i%2)*2) {
				check = true;
				break;
			}
		}
		if(check == false) break;
	}
	cout << (check ? "haiku" : "come back next year") << endl;
	}/////////////
	
	return 0;
}