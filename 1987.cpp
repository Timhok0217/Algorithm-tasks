#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <deque>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cin >> n;
	vector <pair<long long int, long long int>> otrez;

	long long int a = 0;
	long long int b = 0;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		otrez.emplace_back(a, b);
	}

	long int m;
	cin >> m;

	deque <long int> dot(m);
	deque <long int> otv;

	int c = 0;
	int i = 0;

	while (true) {
		cin >> c;
		dot.push_back(c);

		int mid = 0;
		int zapom = 0;
		int zlo = 0;
		int cool = -1;
		int left = 0, right = n - 1;

		while (left <= right) {
			mid = (left + right) / 2;

			if (otrez[mid].first <= dot.back() && dot.back() <= otrez[mid].second) {
				left = mid + 1;
				zapom = mid;
				zlo++;
			}
			if (zapom != 0 && zlo == 0) {
				break;
			}
			if (otrez[mid].first > dot.back()) {
				right = mid - 1;
			}
			if (otrez[mid].second < dot.back()) {
				left = mid + 1;
			}

			zlo = 0;
		}

		for (int i = zapom; i < n; i++) {

			if (dot.back() > otrez[i].second) {
				continue;
			}

			if (dot.back() < otrez[i].first) {
				break;
			}
			cool = i + 1;
		}

		otv.push_back(cool);
		i++;

		if (i == m) {
			break;
		}
	}

	for (int z = 0; z < m; z++) {
		cout << otv[z] << "\n";
	}

	return 0;
}