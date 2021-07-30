#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int zeros = 0;
	for (int i = 5; i <= n; i *= 5)
		zeros += n / i;

	cout << zeros << endl;

	return 0;
}