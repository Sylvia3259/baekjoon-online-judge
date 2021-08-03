#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (;;) {
		int n;
		cin >> n;

		if (!n)
			break;

		for (int j = 3; j <= n / 2; j += 2)
			if (is_prime(j) && is_prime(n - j)) {
				cout << n << " = " << j << " + " << n - j << '\n';
				break;
			}
	}

	return 0;
}