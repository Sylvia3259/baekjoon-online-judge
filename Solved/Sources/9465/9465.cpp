#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100000];

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
			for (int k = 0; k < n; k++)
				cin >> dp[j][k];

		dp[0][1] += dp[1][0];
		dp[1][1] += dp[0][0];

		for (int j = 2; j < n; j++) {
			dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
			dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}

	return 0;
}