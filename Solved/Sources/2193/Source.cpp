#include <iostream>
#include <algorithm>
using namespace std;

long long dp[2][91] = { {0, 0}, {0, 1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}

	cout << dp[0][n] + dp[1][n] << endl;

	return 0;
}