#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int arr[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < n; j++)
			cin >> arr[j];

		long long sum = 0;
		for (int j = 0; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				sum += gcd(arr[j], arr[k]);

		cout << sum << endl;
	}

	return 0;
}