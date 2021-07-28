#include <iostream>
#include <algorithm>
using namespace std;

int p[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + p[1];
		for (int j = 2; j <= i; j++)
			dp[i] = max(dp[i - j] + p[j], dp[i]);
	}

	cout << dp[n] << endl;

	return 0;
}