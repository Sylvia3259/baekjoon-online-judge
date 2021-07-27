#include <iostream>
#include <algorithm>
using namespace std;

int dp[31] = { 0, 0, 3, 0, 11 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 6; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3 + 2;
		for (int j = 2; j <= i - 4; j += 2)
			dp[i] += dp[j] * 2;
	}

	cout << dp[n] << endl;

	return 0;
}