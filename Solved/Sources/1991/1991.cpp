#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<char, char>> tree;

void preorder(char node) {
	if (node == '.')
		return;

	cout << node;
	preorder(tree[node].first);
	preorder(tree[node].second);
}

void inorder(char node) {
	if (node == '.')
		return;

	inorder(tree[node].first);
	cout << node;
	inorder(tree[node].second);
}

void postorder(char node) {
	if (node == '.')
		return;

	postorder(tree[node].first);
	postorder(tree[node].second);
	cout << node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char node, left_child, right_child;
		cin >> node >> left_child >> right_child;

		tree[node].first = left_child;
		tree[node].second = right_child;
	}

	preorder('A');
	cout << endl;

	inorder('A');
	cout << endl;

	postorder('A');
	cout << endl;

	return 0;
}