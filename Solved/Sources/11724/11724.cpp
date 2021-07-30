#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool adj[1001][1001];
bool checked[1001];

void dfs(int n, int v) {
	checked[v] = true;

	for (int i = 1; i <= n; i++)
		if (adj[v][i] && !checked[i])
			dfs(n, i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = adj[to][from] = true;
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
		if (!checked[i]) {
			dfs(n, i);
			count++;
		}

	cout << count << endl;

	return 0;
}