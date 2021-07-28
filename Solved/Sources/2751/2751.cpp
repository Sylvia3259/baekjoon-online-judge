#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}