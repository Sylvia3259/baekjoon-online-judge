#include <iostream>
#include <algorithm>
#include <deque>
#include <functional>
#include <map>
using namespace std;

deque<int> deq;

map<string, function<void()>> m = {
	{
		"push_front",
		[]() {
			int x;
			cin >> x;
			deq.push_front(x);
		}
	},
	{
		"push_back",
		[]() {
			int x;
			cin >> x;
			deq.push_back(x);
		}
	},
	{
		"pop_front",
		[]() {
			if (!deq.empty()) {
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			else
				cout << -1 << '\n';
		}
	},
	{
		"pop_back",
		[]() {
			if (!deq.empty()) {
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
	},
	{
		"size",
		[]() {
			cout << deq.size() << '\n';
		}
	},
	{
		"empty",
		[]() {
			cout << deq.empty() << '\n';
		}
	},
	{
		"front",
		[]() {
			if (!deq.empty())
				cout << deq.front() << '\n';
			else
				cout << -1 << '\n';
		}
	},
	{
		"back",
		[]() {
			if (!deq.empty())
				cout << deq.back() << '\n';
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