#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;

int Fib(int N, int K, deque<int>& arr){
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			arr[0] = K - 1;
		}
		else if (i == 1) {
			arr[1] = K * (K - 1);
		}
		else {
			arr[i] = (arr[i - 1] + arr[i - 2]) * arr[0];
		}
	}
	return arr[N - 1];
}

int main() {
	setlocale(LC_ALL, "Russian");

	int N,K,sum;
	cin >> N;
	cin >> K;

	deque <int> arr(N);

	sum=Fib(N, K, arr);

	cout << sum;

	return 0;
}