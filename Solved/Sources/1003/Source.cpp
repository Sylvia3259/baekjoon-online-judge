#include <iostream>
#include <algorithm>
#include <valarray>
using namespace std;

valarray<int> cache[41] = { {1, 0}, {0, 1} };

valarray<int>& fibonacci(int n) {
	if (n <= 1)
		return cache[n];

	if (!cache[n].size())
		cache[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return cache[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		auto& result = fibonacci(n);
		cout << result[0] << ' ' << result[1] << endl;
	}

	return 0;
}