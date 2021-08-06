#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	const int digits = max(a.size(), b.size());

	int index = 0;
	vector<int> a_vector(digits);
	for (int i = a.size() - 1; i >= 0; i--)
		a_vector[index++] = a[i] - '0';

	index = 0;
	vector<int> b_vector(digits);
	for (int i = b.size() - 1; i >= 0; i--)
		b_vector[index++] = b[i] - '0';

	vector<int> result(digits + 1);
	for (int i = 0; i < digits; i++) {
		result[i] += a_vector[i] + b_vector[i];
		if (result[i] >= 10) {
			result[i + 1] = result[i] / 10;
			result[i] %= 10;
		}
	}
	
	index = result.size();
	while (!result[--index]);
	for (int i = index; i >= 0; i--)
		cout << result[i];

	return 0;
}