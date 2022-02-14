#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;

int val(int n, int maximum, deque<int>& arr) {

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;

	for (int i = 4; i <= n; i++) {
		int minimal = arr[i - 1] + 1;
		for (int k = 1; k <= sqrt(maximum); k++) {
			if (i >= k * k) {
				if (max(minimal, (arr[i - k * k] + 1)) == minimal) {
					minimal = arr[i - k * k] + 1;
				}
			}
			else {
				break;
			}
		}
		arr[i] = minimal;
	}
	return arr[n];
}

int main(){
	setlocale(LC_ALL, "Russian");

	int n,count;
	cin >> n;
	
	int maximum = 60000;

	deque<int> arr(maximum);

	count = val(n, maximum, arr);

	cout << count;

	return 0;
}