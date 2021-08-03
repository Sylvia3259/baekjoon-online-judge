#include <iostream>
#include <algorithm>
using namespace std;

constexpr int mod = 1e9;
int dp[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= k; i++)
		for (int j = 0; j <= n; j++)
			for (int l = 0; l <= j; l++)
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % mod;

	cout << dp[k][n] << endl;

	return 0;
}