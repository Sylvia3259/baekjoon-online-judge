#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int dp[2][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[0][1] = 1;
	dp[1][n] = 1;

	for (int i = 2; i <= n; i++) {
		int max = 0;
		for (int j = 1; j < i; j++)
			if (a[i] > a[j] && max < dp[0][j])
				max = dp[0][j];
		dp[0][i] = max + 1;
	}

	for (int i = n - 1; i >= 1; i--) {
		int max = 0;
		for (int j = n; j > i; j--)
			if (a[i] > a[j] && max < dp[1][j])
				max = dp[1][j];
		dp[1][i] = max + 1;
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
		if (max < dp[0][i] + dp[1][i])
			max = dp[0][i] + dp[1][i];

	cout << max - 1 << endl;

	return 0;
}