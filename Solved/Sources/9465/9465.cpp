#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= n; k++)
				cin >> dp[j][k];

		dp[0][2] += dp[1][1];
		dp[1][2] += dp[0][1];

		for (int j = 3; j <= n; j++) {
			dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
			dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);
		}

		cout << max(dp[0][n], dp[1][n]) << endl;
	}

	return 0;
}