#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int tree[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> tree[i];

	int low = 0;
	int high = INT_MAX;

	while (low <= high) {
		int height = (low + high) / 2;

		long long length = 0;
		for (int i = 0; i < n; i++)
			length += max(0, tree[i] - height);

		if (length < m)
			high = height - 1;
		else if (length >= m)
			low = height + 1;
	}

	cout << high << endl;

	return 0;
}