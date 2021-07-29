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

	for (char c : s)
		arr[c - 'a']++;

	for (int freq : arr)
		cout << freq << ' ';

	return 0;
}