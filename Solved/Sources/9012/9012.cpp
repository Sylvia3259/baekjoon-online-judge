#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string ps;
		cin >> ps;

		int stack = 0;
		for (char c : ps) {
			if (c == '(')
				stack++;
			else if (c == ')')
				if (!stack--)
					break;
		}

		cout << (stack ? "NO" : "YES") << '\n';
	}

	return 0;
}