#include <iostream>
#include <algorithm>
#include <valarray>
using namespace std;

int paper[2187][2187];

inline bool is_single_chunk(int x1, int y1, int x2, int y2) {
	const int value = paper[y1][x1];

	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++)
			if (paper[i][j] != value)
				return false;

	return true;
}

valarray<int> cut_paper(int x1, int y1, int x2, int y2) {
	valarray<int> result(3);
	const int side = (x2 - x1) / 3;

	if (is_single_chunk(x1, y1, x2, y2)) {
		result[paper[y1][x1] + 1] = 1;
		return result;
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			result += cut_paper(
				x1 + side * j, y1 + side * i,
				x1 + side * (j + 1), y1 + side * (i + 1)
			);
		}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	for (int result : cut_paper(0, 0, n, n))
		cout << result << endl;

	return 0;
}