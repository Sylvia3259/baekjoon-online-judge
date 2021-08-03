#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> x;

int get_index(int value) {
	static vector<int> index;
	if (!index.size()) {
		index = x;
		sort(index.begin(), index.end());
		index.erase(unique(index.begin(), index.end()), index.end());
	}

	return lower_bound(index.begin(), index.end(), value) - index.begin();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	x.resize(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	for (int i = 0; i < n; i++)
		cout << get_index(x[i]) << ' ';

	return 0;
}