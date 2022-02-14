#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <deque>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int M;
	cin >> M;
	
	deque <long int> st(M);
	vector <long int> otv;

	int col_el = 0;

	while (true) {

		long int N;
		cin >> N;

		if (N == -1) {
			break;
		}

		st.push_front(N); 

		if (col_el != M) {
			col_el++;
		}

		if (col_el == M) {
			long int max = st[0];
			for (int i = 0; i < M; ++i) {
				if (st[i] > max) {
					max = st[i];
				}
			}
			otv.push_back(max);
			st.pop_back();
		}
	}	
	
	for (int i = 0; i < otv.size(); i++) {
		cout << otv[i]<<"\n";
	}

	return 0;
}