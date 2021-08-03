#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int value;
		cin >> value;

		cout << binary_search(arr, arr + n, value) << ' ';
	}

	return 0;
}