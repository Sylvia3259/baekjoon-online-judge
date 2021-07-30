#include <iostream>
#include <algorithm>
using namespace std;

char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convert(int n, int b) {
	if (!n)
		return;

	convert(n / b, b);
	cout << digit[n % b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, b;
	cin >> n >> b;

	convert(n, b);

	return 0;
}