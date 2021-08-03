#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	vector<string> suffixes;
	for (int i = 0; i < s.length(); i++)
		suffixes.push_back(&s[i]);

	sort(suffixes.begin(), suffixes.end());

	for (const auto& suffix : suffixes)
		cout << suffix << '\n';

	return 0;
}