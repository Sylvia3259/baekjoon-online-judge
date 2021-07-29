#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	list<char> l(s.begin(), s.end());

	int m;
	cin >> m;

	list<char>::iterator cursor = l.end();
	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;

		if (command == 'L') {
			if (cursor != l.begin())
				--cursor;
		}
		else if (command == 'D') {
			if (cursor != l.end())
				++cursor;
		}
		else if (command == 'B') {
			if (cursor != l.begin()) {
				--cursor;
				l.erase(cursor++);
			}
		}
		else if (command == 'P') {
			char c;
			cin >> c;
			l.insert(cursor, c);
		}
	}

	string result(l.begin(), l.end());
	cout << result << endl;

	return 0;
}