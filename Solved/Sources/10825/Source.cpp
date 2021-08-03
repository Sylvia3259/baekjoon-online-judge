#include <iostream>
#include <algorithm>
using namespace std;

struct student {
	string name;
	int korean;
	int english;
	int math;
};

student arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;

	sort(arr, arr + n, [](const auto& lhs, const auto& rhs) {
		if (lhs.korean != rhs.korean)
			return lhs.korean > rhs.korean;
		if (lhs.english != rhs.english)
			return lhs.english < rhs.english;
		if (lhs.math != rhs.math)
			return lhs.math > rhs.math;
		return lhs.name < rhs.name;
	});

	for (int i = 0; i < n; i++)
		cout << arr[i].name << '\n';

	return 0;
}