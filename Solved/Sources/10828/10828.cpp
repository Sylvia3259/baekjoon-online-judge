#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <stack>
using namespace std;

stack<int> s;

map<string, function<void()>> m = {
	{
		"push",
		[]() {
			int x;
			cin >> x;
			s.push(x);
		}
	},
	{
		"pop",
		[]() {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
	},
	{
		"size",
		[]() {
			cout << s.size() << '\n';
		}
	},
	{
		"empty",
		[]() {
			cout << s.empty() << '\n';
		}
	},
	{
		"top",
		[]() {
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';
		}
	},
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		m[command]();
	}

	return 0;
}