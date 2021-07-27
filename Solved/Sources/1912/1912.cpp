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

	for (int i = 1; i <= n; i++)
		cin >> dp[i];

	for (int i = 2; i <= n; i++)
		dp[i] = max(dp[i], dp[i - 1] + dp[i]);

	cout << *max_element(&dp[1], &dp[n + 1]) << endl;

	return 0;
}