#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int segment_tree[1 << 18];

int init(int node, int start, int end) {
	if (start == end) {
		segment_tree[node] = 1;
		return segment_tree[node];
	}

	const int middle = (start + end) / 2;

	segment_tree[node]
		= init(node * 2, start, middle)
		+ init(node * 2 + 1, middle + 1, end);
	return segment_tree[node];
}

int query(int node, int start, int end, int index) {
	if (start == end) {
		while (node) {
			segment_tree[node]--;
			node /= 2;
		}

		return start;
	}

	const int middle = (start + end) / 2;
	const int left_sum = segment_tree[node * 2];

	if (index <= left_sum)
		return query(node * 2, start, middle, index);
	else
		return query(node * 2 + 1, middle + 1, end, index - left_sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	init(1, 1, n);

	cout << '<';
	int index = 1;
	for (;;) {
		const int count = segment_tree[1];
		index = (index + k - 1) % count;
		if (!index)
			index = count;

		cout << query(1, 1, n, index);

		if (count > 1)
			cout << ", ";
		else
			break;
	}
	cout << '>';

	return 0;
}