#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 1; i < 10001; i++)
		while (arr[i]--)
			cout << i << '\n';

	return 0;
}