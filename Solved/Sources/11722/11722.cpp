#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int dp[1001] = { 0, 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 2; i <= n; i++) {
		int max = 0;
		for (int j = 1; j < i; j++)
			if (a[i] < a[j] && max < dp[j])
				max = dp[j];
		dp[i] = max + 1;
	}

	cout << *max_element(&dp[1], &dp[n + 1]) << endl;

	return 0;
}