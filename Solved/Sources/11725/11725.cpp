#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[100001];
bool checked[100001];
int parent[100001];

void find_parent(int node, int previous) {
	if (checked[node])
		return;

	checked[node] = true;
	parent[node] = previous;

	for (int adj_node : adj[node])
		find_parent(adj_node, node);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	find_parent(1, 0);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';

	return 0;
}