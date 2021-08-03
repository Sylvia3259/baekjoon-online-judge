#include <iostream>
#include <algorithm>
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
	for (int i = 0; i < m; i++) {
		int digit;
		cin >> digit;
		dec = dec * a + digit;
	}

	convert(dec, b);

	return 0;
}