#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int factorial = 1;
	for (int i = 1; i <= n; i++)
		factorial *= i;

	cout << factorial << endl;

	return 0;
}