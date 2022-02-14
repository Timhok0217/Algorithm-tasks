#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int comp_for_right(const vector<int>& a, const vector<int>& b) {
	return a[1] < b[1];
}

int comp_for_left(const vector<int>& a, const vector<int>& b) {
	return a[0] < b[0];
}


int main() {
	setlocale(LC_ALL, "Russian");

	int n, temp, max, help;
	int count=0, zero=0;

	cin >> n;
	vector < vector <int> > col_otr(n, vector <int>(2));  
	vector < vector <int> > otv(n, vector <int>(2));

	for (int i = 0; i < n; i++) {     
		for (int j = 0; j < 2; j++) { 
			cin >> col_otr[i][j]; 
		}
	}

	for (int i = 0; i < n; i++) {     
		for (int j = 1; j < 2; j++) { 
			if ((col_otr[i][j-1] > col_otr[i][j]) && (j==1)) {
				temp = col_otr[i][j-1];
				col_otr[i][j -1] = col_otr[i][j];
				col_otr[i][j] = temp;
			}  
		}
	}

	sort(col_otr.begin(), col_otr.end(), comp_for_right);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == 0) {
				otv[i][j] = col_otr[i][j];
				max = col_otr[i][1];
			}
			else {
				if (col_otr[i][0] >= max) {
					otv[i][j] = col_otr[i][j];
					if (j == 1) {
						max = col_otr[i][1];
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if ((j == 1) && ((otv[i][0] != 0) || (otv[i][1] != 0))) count++;
		}
	}

	sort(otv.begin(), otv.end(), comp_for_left);

	cout << count << "\n";
	for (int i = 0; i < n; i++) {     
		for (int j = 0; j < 2; j++) {
			if (j == 0) help = otv[i][0];
			if ((help == 0) && (otv[i][1] == 0)) {
				zero++;
			}
			else {
				cout << otv[i][j] << " ";
				if ((j == 1) && (otv[i][0] != 0) && (otv[i][1] != 0)) cout << "\n";
			}
		}
	}

	return 0;
}