#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <queue>
using namespace std;

queue<int> q;

map<string, function<void()>> m = {
	{
		"push",
		[]() {
			int x;
			cin >> x;
			q.push(x);
		}
	},
	{
		"pop",
		[]() {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << -1 << '\n';
		}
	},
	{
		"size",
		[]() {
			cout << q.size() << '\n';
		}
	},
	{
		"empty",
		[]() {
			cout << q.empty() << '\n';
		}
	},
	{
		"front",
		[]() {
			if (!q.empty())
				cout << q.front() << '\n';
			else
				cout << -1 << '\n';
		}
	},
	{
		"back",
		[]() {
			if (!q.empty())
				cout << q.back() << '\n';
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