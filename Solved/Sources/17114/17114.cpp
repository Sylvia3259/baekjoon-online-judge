#ifdef __GNUC__
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int vector_size = 11;
int box[1000000];

#ifdef __GNUC__
vector<int> to_coord(int index, const vector<int>& size) __attribute__((always_inline));
int to_index(const vector<int>& coord, const vector<int>& size) __attribute__((always_inline));
vector<vector<int>> get_next_coords(const vector<int>& coord) __attribute__((always_inline));
bool is_vaild(const vector<int>& coord, int index, const vector<int>& size) __attribute__((always_inline));
int bfs(const vector<int>& size, int length) __attribute__((always_inline));
#endif

vector<int> to_coord(int index, const vector<int>& size) {
	vector<int> coord(vector_size);
	for (int i = 0; i < vector_size; i++) {
		coord[i] = index % size[i];
		index /= size[i];

		if (!index)
			break;
	}

	return coord;
}

int to_index(const vector<int>& coord, const vector<int>& size) {
	static vector<int> mul;
	if (!mul.size()) {
		mul.resize(vector_size);

		mul[0] = 1;
		for (int i = 1; i < vector_size; i++)
			mul[i] = mul[i - 1] * size[i - 1];
	}

	int index = 0;
	for (int i = 0; i < vector_size; i++)
		index += coord[i] * mul[i];

	return index;
}

vector<vector<int>> get_next_coords(const vector<int>& coord) {
	vector<vector<int>> next_coords(vector_size * 2, coord);
	for (int i = 0; i < vector_size; i++) {
		next_coords[i * 2 + 0][i]--;
		next_coords[i * 2 + 1][i]++;
	}

	return next_coords;
}

bool is_vaild(const vector<int>& coord, int index, const vector<int>& size) {
	for (int i = 0; i < vector_size; i++)
		if (coord[i] < 0 || size[i] <= coord[i])
			return false;

	if (box[index] != 0)
		return false;

	return true;
};

int bfs(const vector<int>& size, int length) {
	queue<int> q;

	int unripe = 0;
	for (int i = 0; i < length; i++)
		if (box[i] == 0)
			unripe++;
		else if (box[i] == 1)
			q.push(i);

	if (!unripe)
		return 0;

	int day = 0;
	while (!q.empty() && ++day) {
		const int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			const int index = q.front();
			const auto coord = to_coord(index, size);
			q.pop();

			for (auto& next_coord : get_next_coords(coord)) {
				const int next_index = to_index(next_coord, size);
				if (is_vaild(next_coord, next_index, size)) {
					q.push(next_index);
					box[next_index] = 1;
					unripe--;
				}
			}
		}
	}

	if (unripe)
		return -1;

	return day - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n, o, p, q, r, s, t, u, v, w;
	cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;

	vector<int> size = { m, n, o, p, q, r, s, t, u, v, w };
	int length = m * n * o * p * q * r * s * t * u * v * w;

	for (int i = 0; i < length; i++)
		cin >> box[i];

	cout << bfs(size, length) << endl;

	return 0;
}