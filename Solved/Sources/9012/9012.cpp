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

		int length = ps.length();
		int stack = 0;
		for (int j = 0; j < length; j++) {
			if (ps[j] == '(')
				stack++;
			else if (ps[j] == ')')
				if (!stack--)
					break;
		}

		cout << (stack ? "NO" : "YES") << '\n';
	}

	return 0;
}