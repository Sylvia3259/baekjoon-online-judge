#include <iostream>
#include <algorithm>
using namespace std;

long long input[1'000'001];
long long segment_tree[1 << 21];

long long init(int node, int start, int end) {
	if (start == end) {
		segment_tree[node] = input[start];
		return segment_tree[node];
	}

	segment_tree[node] =
		init(node * 2, start, (start + end) / 2) +
		init(node * 2 + 1, (start + end) / 2 + 1, end);

	return segment_tree[node];
}

long long update(int node, int start, int end, int index, long long value) {
	long long diff;

	if (start == end) {
		diff = value - segment_tree[node];
		segment_tree[node] = value;
		return diff;
	}

	if (index <= (start + end) / 2)
		diff = update(node * 2, start, (start + end) / 2, index, value);
	else
		diff = update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);

	segment_tree[node] += diff;
	return diff;
}

long long sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right)
		return segment_tree[node];
	else if (end < left || right < start)
		return 0;
	else
		return
			sum(node * 2, start, (start + end) / 2, left, right) +
			sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> input[i];

	init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			update(1, 1, n, b, c);
		else if (a == 2)
			cout << sum(1, 1, n, b, c) << '\n';
	}

	return 0;
}