#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int adj[100001];
bool checked[100001];
bool finished[100001];

int find_cycle(int node) {
	if (checked[node]) {
		if (!finished[node])
			return node;
		return 0;
	}

	checked[node] = true;
	int cycle_start = find_cycle(adj[node]);
	finished[node] = true;

	return cycle_start;
}

int cycle_size(int start) {
	int cycle_size = 0;

	int node = start;
	for (;;) {
		if (cycle_size && node == start)
			break;
		node = adj[node];
		cycle_size++;
	}

	return cycle_size;
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
			adj[from] = to;
		}

		int count = 0;
		for (int j = 1; j <= n; j++)
			if (!checked[j]) {
				int cycle_start = find_cycle(j);
				if (cycle_start)
					count += cycle_size(cycle_start);
			}

		cout << n - count << endl;

		for (int j = 1; j <= n; j++) {
			adj[j] = 0;
			checked[j] = finished[j] = false;
		}
	}

	return 0;
}