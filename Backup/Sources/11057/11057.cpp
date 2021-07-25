#include <iostream>
#include <algorithm>
using namespace std;

constexpr int mod = 10007;
int dp[10][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[i][1] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= j; k++)
				dp[j][i] = (dp[j][i] + dp[k][i - 1]) % mod;

	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[i][n]) % mod;

	cout << sum << endl;

	return 0;
}