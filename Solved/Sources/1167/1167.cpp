#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[100001];
bool checked[2][100001];
int max_distance[2], max_node[2];

void dfs(int node, int sum, int index) {
	if (checked[index][node])
		return;

	checked[index][node] = true;

	if (sum > max_distance[index]) {
		max_distance[index] = sum;
		max_node[index] = node;
	}

	for (auto adj_node : adj[node])
		dfs(adj_node.first, sum + adj_node.second, index);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int from;
		cin >> from;

		for (;;) {
			int to;
			cin >> to;
			if (to == -1)
				break;

			int weight;
			cin >> weight;

			adj[from].push_back({ to, weight });
			adj[to].push_back({ from, weight });
		}
	}

	dfs(1, 0, 0);
	dfs(max_node[0], 0, 1);

	cout << max_distance[1] << endl;

	return 0;
}