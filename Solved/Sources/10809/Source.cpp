#include <iostream>
#include <algorithm>
using namespace std;

int arr[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int index = s[i] - 'a';
		if (!arr[index])
			arr[index] = i + 1;
	}

	for (int index : arr)
		cout << index - 1 << ' ';

	return 0;
}