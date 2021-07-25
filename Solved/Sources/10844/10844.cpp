#include <iostream>
#include <algorithm>
using namespace std;

constexpr int mod = 1e9;
int dp[10][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++)
		dp[i][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[1][i - 1];
		for (int j = 1; j <= 8; j++)
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % mod;
		dp[9][i] = dp[8][i - 1];
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[i][n]) % mod;

	cout << sum << endl;

	return 0;
}