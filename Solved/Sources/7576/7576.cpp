#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int box[1000][1000];

int bfs(int m, int n) {
	const pair<int, int> deltas[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	const auto vaild = [&](int x, int y) {
		return (0 <= x && x < m) && (0 <= y && y < n) && box[y][x] == 0;
	};

	queue<pair<int, int>> q;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (box[y][x] == 1)
				q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto& delta : deltas) {
			int next_x = x + delta.first;
			int next_y = y + delta.second;

			if (vaild(next_x, next_y)) {
				q.push({ next_x, next_y });
				box[next_y][next_x] = box[y][x] + 1;
			}
		}
	}

	int day = 0;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (!box[y][x])
				return 0;
			else
				day = max(box[y][x], day);

	return day;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> box[y][x];

	cout << bfs(m, n) - 1 << endl;

	return 0;
}