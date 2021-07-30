#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int checked[1000000];

int next(int a, int p) {
	int sum = 0;

	while (a) {
		sum += pow(a % 10, p);
		a /= 10;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, p;
	cin >> a >> p;

	for (int i = 1; !checked[a]; i++) {
		checked[a] = i;
		a = next(a, p);
	}

	cout << checked[a] - 1 << endl;

	return 0;
}