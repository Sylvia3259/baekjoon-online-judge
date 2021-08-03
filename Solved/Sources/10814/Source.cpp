#include <iostream>
#include <algorithm>
using namespace std;

pair<int, string> arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	stable_sort(arr, arr + n, [](const auto& lhs, const auto& rhs) { 
		return lhs.first < rhs.first; 
	});

	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';

	return 0;
}