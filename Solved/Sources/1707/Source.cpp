#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[20001];
bool checked[20001];
bool node_class[20001];

bool is_bipartite(int start) {
	queue<int> q;

	q.push(start);
	checked[start] = true;
	node_class[start] = false;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int adj_node : adj[node]) {
			if (!checked[adj_node]) {
				q.push(adj_node);
				checked[adj_node] = true;
				node_class[adj_node] = !node_class[node];
			}
			else if (node_class[node] == node_class[adj_node])
				return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int v, e;
		cin >> v >> e;

		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		bool flag = true;
		for (int j = 1; j <= v; j++)
			if (!checked[j] && !is_bipartite(j))
				flag = false;

		cout << (flag ? "YES" : "NO") << endl;

		for (int j = 1; j <= v; j++) {
			adj[j].clear();
			checked[j] = false;
		}
	}

	return 0;
}