#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void convert(int n) {
	if (n == 0 || n == 1) {
		cout << n;
		return;
	}

	convert((int)ceil(n / -2.));
	cout << abs(n % -2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	convert(n);

	return 0;
}