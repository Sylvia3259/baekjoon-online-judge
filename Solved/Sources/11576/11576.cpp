#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void convert(int n, int b) {
	if (!n)
		return;

	convert(n / b, b);
	cout << n % b << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	int m;
	cin >> a >> b;
	cin >> m;

	int dec = 0;
	int power = pow(a, m - 1);
	for (int i = 0; i < m; i++) {
		int digit;
		cin >> digit;
		dec += digit * power;
		power /= a;
	}

	convert(dec, b);

	return 0;
}