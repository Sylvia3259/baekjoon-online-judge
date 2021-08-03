#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	nth_element(arr, arr + k - 1, arr + n);

	cout << arr[k - 1] << endl;

	return 0;
}