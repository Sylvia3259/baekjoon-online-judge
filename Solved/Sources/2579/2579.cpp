#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> dp[1][i];
		dp[2][i] = dp[1][i];
	}

	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] += dp[0][i - 1];
		dp[2][i] += dp[1][i - 1];
	}

	cout << max(dp[1][n], dp[2][n]) << endl;

	return 0;
}