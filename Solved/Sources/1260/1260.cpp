#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool adj[1001][1001];
bool visited[2][1001];

void dfs(int n, int v) {
	visited[0][v] = true;
	cout << v << ' ';

	for (int i = 1; i <= n; i++)
		if (adj[v][i] && !visited[0][i])
			dfs(n, i);
}

void bfs(int n, int v) {
	queue<int> q;

	q.push(v);
	visited[1][v] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		cout << v << ' ';

		for (int i = 1; i <= n; i++)
			if (adj[v][i] && !visited[1][i]) {
				q.push(i);
				visited[1][i] = true;
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = adj[to][from] = true;
	}

	dfs(n, v);
	cout << endl;

	bfs(n, v);
	cout << endl;

	return 0;
}