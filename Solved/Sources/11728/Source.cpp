#include <iostream>
#include <algorithm>
using namespace std;

int arr1[1000001];
int arr2[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	arr1[n] = 0x7fffffff;

	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	arr2[m] = 0x7fffffff;

	int index1 = 0;
	int index2 = 0;

	for (;;) {
		if (index1 == n && index2 == m)
			break;

		if (arr1[index1] < arr2[index2])
			cout << arr1[index1++] << ' ';
		else
			cout << arr2[index2++] << ' ';
	}

	return 0;
}