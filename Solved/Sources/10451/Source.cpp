#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool adj[1001][1001];
bool checked[1001];

void dfs(int node, int count) {
	checked[node] = true;

	for (int i = 1; i <= count; i++)
		if (adj[node][i] && !checked[i])
			dfs(i, count);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int from = 1; from <= n; from++) {
			int to;
			cin >> to;
			adj[from][to] = true;
		}

		int count = 0;
		for (int j = 1; j <= n; j++)
			if (!checked[j]) {
				dfs(j, n);
				count++;
			}

		cout << count << endl;

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++)
				adj[j][k] = false;
			checked[j] = false;
		}
	}

	return 0;
}