#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	cout << gcd(n, m) << endl;
	cout << lcm(n, m) << endl;

	return 0;
}