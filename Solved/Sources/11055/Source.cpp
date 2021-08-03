#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}

	for (int i = 2; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
				tmp = max(dp[j], tmp);
		dp[i] += tmp;
	}

	cout << *max_element(&dp[1], &dp[n + 1]) << endl;

	return 0;
}