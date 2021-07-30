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

	int n;
	cin >> n;

	int primes = 0;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		primes += is_prime(number);
	}

	cout << primes << endl;

	return 0;
}