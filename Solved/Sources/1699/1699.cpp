#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j * j <= i; j++)
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
	}

	cout << dp[n] << endl;

	return 0;
}