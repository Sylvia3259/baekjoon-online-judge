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
		int tmp = 0;
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
				tmp = max(dp[0][j], tmp);
		dp[0][i] = tmp + 1;
	}

	for (int i = n - 1; i >= 1; i--) {
		int tmp = 0;
		for (int j = n; j > i; j--)
			if (a[i] > a[j])
				tmp = max(dp[1][j], tmp);
		dp[1][i] = tmp + 1;
	}

	int tmp = 0;
	for (int i = 1; i <= n; i++)
		tmp = max(dp[0][i] + dp[1][i], tmp);

	cout << tmp - 1 << endl;

	return 0;
}