#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<long long, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		m[tmp]++;
	}

	auto tmp = max_element(m.begin(), m.end(), [](const auto& lhs, const auto& rhs) {
		if (lhs.second == rhs.second)
			return lhs.first > rhs.first;
		return lhs.second < rhs.second;
	});

	cout << tmp->first << endl;

	return 0;
}