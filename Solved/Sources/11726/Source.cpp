#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = { 0, 1, 2 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	cout << dp[n] << endl;

	return 0;
}