//https://www.acmicpc.net/problem/17839

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n;
map<string, vector<string>> dict;
map<string, int> visited;
queue<string> q;

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string p, is, q;
		cin >> p >> is >> q;

		dict[p].push_back(q);
	}

	string Baba = "Baba";

	vector<string> ans;

	q.push("Baba");

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		for (int i = 0; i < dict[cur].size(); i++) {
			if (visited[dict[cur][i]] != 0) continue;
			visited[dict[cur][i]] += 1;
			ans.push_back(dict[cur][i]);
			q.push(dict[cur][i]);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != "")
			cout << ans[i] << "\n";
	}

	getchar();
	getchar();

	return 0;
}