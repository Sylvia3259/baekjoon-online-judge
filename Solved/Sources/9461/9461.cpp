#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101] = { 0, 1, 1, 1, 2, 2 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int j = 6; j <= n; j++)
			dp[j] = dp[j - 5] + dp[j - 1];

		cout << dp[n] << endl;
	}

	return 0;
}