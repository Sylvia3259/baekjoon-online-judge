#include <iostream>
#include <algorithm>
using namespace std;

int x[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> x[i];

	sort(x, x + n);

	int left = 1;
	int right = x[n - 1];

	while (left <= right) {
		int distance = (left + right) / 2;

		int count = 1;
		int previous = 0;
		for (int i = 1; i < n; i++)
			if (x[i] - x[previous] >= distance) {
				previous = i;
				count++;
			}

		if (count < c)
			right = distance - 1;
		else if (count >= c)
			left = distance + 1;
	}

	cout << right << endl;

	return 0;
}