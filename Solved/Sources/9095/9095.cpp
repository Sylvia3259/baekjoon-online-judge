#include <iostream>
#include <algorithm>
using namespace std;

int dp[11] = { 0, 1, 2, 4 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int j = 4; j <= n; j++)
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];

		cout << dp[n] << endl;
	}

	return 0;
}