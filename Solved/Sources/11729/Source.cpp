#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void hanoi_tower(int n, int source, int auxiliary, int destination) {
	if (n == 1) {
		cout << source << ' ' << destination << '\n';
		return;
	}

	hanoi_tower(n - 1, source, destination, auxiliary);
	hanoi_tower(1, source, auxiliary, destination);
	hanoi_tower(n - 1, auxiliary, source, destination);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << endl;
	hanoi_tower(n, 1, 2, 3);

	return 0;
}