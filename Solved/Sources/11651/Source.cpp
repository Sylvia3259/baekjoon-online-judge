#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i].second << ' ' << arr[i].first << '\n';

	return 0;
}