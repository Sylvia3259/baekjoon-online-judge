#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
		if (is_prime(i))
			cout << i << '\n';

	return 0;
}