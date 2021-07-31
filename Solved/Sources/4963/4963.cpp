#include <iostream>
#include <algorithm>
using namespace std;

bool map[52][52];

void dfs(int x, int y, int w, int h) {
	if (!map[y][x])
		return;

	map[y][x] = false;

	for (int dy = -1; dy <= 1; dy++)
		for (int dx = -1; dx <= 1; dx++)
			if (dx || dy)
				dfs(x + dx, y + dy, w, h);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (;;) {
		int w, h;
		cin >> w >> h;

		if (!w && !h)
			break;

		for (int y = 1; y <= h; y++)
			for (int x = 1; x <= w; x++)
				cin >> map[y][x];

		int count = 0;
		for (int y = 1; y <= h; y++)
			for (int x = 1; x <= w; x++)
				if (map[y][x]) {
					dfs(x, y, w, h);
					count++;
				}

		cout << count << endl;
	}

	return 0;
}