#include <iostream>
#include <algorithm>
using namespace std;

long long lan[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k, n;
	cin >> k >> n;

	long long left = 1;
	long long right = -1;

	for (int i = 0; i < k; i++) {
		cin >> lan[i];

		right = max(lan[i], right);
	}

	while (left <= right) {
		long long length = (left + right) / 2;

		int count = 0;
		for (int i = 0; i < k; i++)
			count += lan[i] / length;

		if (count < n)
			right = length - 1;
		else if (count >= n)
			left = length + 1;
	}

	cout << right << endl;

	return 0;
}