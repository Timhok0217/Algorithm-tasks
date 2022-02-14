#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <deque>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	long int N;
	cin >> N;

	deque <long int> sherif;
	vector <long int> otv;

	int j = 0;
	int z = 0;
	int key_true = 0;
	int zlo = 0;
	int one_first=0;

	while (true) {
		long int numbers;
		cin >> numbers;

		while (key_true != 0) {
			if (sherif.empty() == false) {
				if (sherif.back() == numbers) {
					sherif.pop_back();
					key_true++;
				}
				else {
					key_true = 0;
				}
			}
			else {
				key_true = 0;
			}
		}

		if (sherif.size()==0) {
			sherif.push_back(1);
			one_first++;
		}

		for (int i = z; i < numbers; i++) {
			for (int j = z; j < otv.size(); j++) {
				if ((sherif.front() + i) == otv[j]) {
					zlo++;
					break;
				}
			}		
			if (zlo == 0) {
				sherif.push_back(i + 1);
				otv.push_back(i+1);
			}
			zlo = 0;
			z = numbers;
		}

		if (sherif.back() == numbers)  {
			sherif.pop_back();
			key_true++;
		}
		else {
			key_true = 0;
		}

		j++;
		if (j == N) {
			break;
		}
	}
	
	if (sherif.empty()||((sherif.front()==1)&&(one_first > 0)&&(sherif.size()==1))) {
		cout << "Not a proof";
	}
	else {
		cout << "Cheater";
	}

	return 0;
}