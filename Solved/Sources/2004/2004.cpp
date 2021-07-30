#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> count_two_and_five(int factorial) {
	int two = 0;
	for (long long i = 2; i <= factorial; i *= 2)
		two += factorial / i;

	int five = 0;
	for (long long i = 5; i <= factorial; i *= 5)
		five += factorial / i;

	return make_pair(two, five);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto n_count = count_two_and_five(n);
	auto n_m_count = count_two_and_five(n - m);
	auto m_count = count_two_and_five(m);

	int two = n_count.first - n_m_count.first - m_count.first;
	int five = n_count.second - n_m_count.second - m_count.second;

	cout << min(two, five) << endl;

	return 0;
}