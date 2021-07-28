#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string vps;
	cin >> vps;

	string::size_type pos = 0;
	while ((pos = vps.find("()", pos)) != string::npos)
		vps.replace(pos++, 2, "*");

	int stack = 0;
	int pieces = 0;
	for (char c : vps) {
		if (c == '(')
			stack++;
		else if (c == ')') {
			stack--;
			pieces++;
		}
		else if (c == '*')
			pieces += stack;
	}

	cout << pieces << endl;

	return 0;
}