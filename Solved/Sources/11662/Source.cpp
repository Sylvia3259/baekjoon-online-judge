#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

double f(const vector<int>& args, double t) {
	const double x1 = args[0] + (args[2] - args[0]) * t;
	const double y1 = args[1] + (args[3] - args[1]) * t;

	const double x2 = args[4] + (args[6] - args[4]) * t;
	const double y2 = args[5] + (args[7] - args[5]) * t;

	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	const vector<int> args = { ax, ay, bx, by, cx, cy, dx, dy };

	double start = 0;
	double end = 1;

	while (end - start > 1e-9) {
		const double t1 = (start + start + end) / 3;
		const double t2 = (start + end + end) / 3;

		const double d1 = f(args, t1);
		const double d2 = f(args, t2);

		if (d1 < d2)
			end = t2;
		else
			start = t1;
	}

	cout.precision(10);
	cout << fixed;
	cout << f(args, (start + end) / 2) << endl;

	return 0;
}