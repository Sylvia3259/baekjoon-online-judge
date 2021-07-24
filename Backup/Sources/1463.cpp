#include <iostream>
#include <algorithm>
using namespace std;

int min_count = 1000000;

void f(int n, int d) {
	if (n == 1) {
		min_count = d < min_count ? d : min_count;
		return;
	}
	if (d > min_count)
		return;

	if (n % 3 == 0)
		f(n / 3, d + 1);
	if (n % 2 == 0)
		f(n / 2, d + 1);
	f(n - 1, d + 1);
}

int main() {
	int n;
	cin >> n;
	f(n, 0);
	cout << min_count;

	return 0;
}