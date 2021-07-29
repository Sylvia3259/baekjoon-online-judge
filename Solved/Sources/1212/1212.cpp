#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

const char* oct_to_bin[] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string oct;
	cin >> oct;

	string bin;
	for (char digit : oct)
		bin.append(oct_to_bin[digit - '0']);

	bin.erase(bin.begin(), find_if(bin.begin(), bin.end() - 1, [](char c) {
		return c == '1';
	}));

	cout << bin << endl;

	return 0;
}