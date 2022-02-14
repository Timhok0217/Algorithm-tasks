#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double res;

void result(vector<double>& a, vector<double>& c, int n){
	for (int i = 2; i <= n; i++) {
		a[i] = 2 * (a[i - 1] + c[i - 1]) - a[i - 2];
	}
	res = 2 * (a[n] + c[n]) - a[n - 1];
}

void bin_poisk(vector<double>& a, vector<double>& c, int n, const double epsilon) {
	double left = -2000;
	double right = 2000;
	while (left - right < epsilon) {
		double middle = (left + right) / 2;
		a[1] = middle;
		result(a, c, n);
		if (fabs(a[n + 1] - res) < epsilon) {
			cout << fixed << setprecision(2) << middle;
			break;
		}
		else {
			if ((a[n + 1] - res) < epsilon) {
				right = middle;
			}
			else {
				left = middle;
			}
		}
	}

}

int main(){
	setlocale(LC_ALL, "Russian");

	int n;
	const double epsilon = 1e-3;

	cin >> n;
	vector <double> a(n+2);
	vector <double> c(n+1);
	cin >> a[0] >> a[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	bin_poisk(a, c, n, epsilon);

	return 0;
}