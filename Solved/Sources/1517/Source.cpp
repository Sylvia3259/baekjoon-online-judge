#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
int segment_tree[1 << 20];

int get_index(int value) {
	static vector<int> index;
	if (!index.size()) {
		index = a;
		sort(index.begin(), index.end());
		index.erase(unique(index.begin(), index.end()), index.end());
	}

	return lower_bound(index.begin(), index.end(), value) - index.begin() + 1;
}

int sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right)
		return segment_tree[node];
	else if (end < left || right < start)
		return 0;
	else
		return
			sum(node * 2, start, (start + end) / 2, left, right) +
			sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int index) {
	segment_tree[node]++;
	if (start == end)
		return;

	if (index <= (start + end) / 2)
		update(node * 2, start, (start + end) / 2, index);
	else
		update(node * 2 + 1, (start + end) / 2 + 1, end, index);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long swap = 0;
	for (int i = n - 1; i >= 0; i--) {
		const int index = get_index(a[i]);
		swap += sum(1, 1, n, 1, index - 1);
		update(1, 1, n, index);
	}

	cout << swap << endl;

	return 0;
}