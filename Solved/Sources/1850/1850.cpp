#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	cout << string(gcd(a, b), '1') << endl;

	return 0;
}