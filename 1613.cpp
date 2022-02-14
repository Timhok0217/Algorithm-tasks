#include <iostream>
#include <algorithm>
#include <vector>
#define less_than 70001

using namespace std;

long int l, r, x, n;

struct goroda {
	long int chislo_lyd;
	long int index;
	goroda(long int chislo_lyd = 0, long int index = 0) {
		this->chislo_lyd = chislo_lyd; this->index = index;
	}
} mass[less_than];

int comp(goroda for_one, goroda for_second) {
	if (for_one.chislo_lyd == for_second.chislo_lyd) {
		return for_one.index < for_second.index; //Если число перевезенных людей совпадает, то сортируем их индексы	
	}
	else {
		return for_one.chislo_lyd < for_second.chislo_lyd;
	}
}

int Poisk_po_zapr(long int x, long int l, long int r) {
	long int right_gran = upper_bound(mass, mass + n, goroda(x, r), comp) - mass;
	long int lev_gran = lower_bound(mass, mass + n, goroda(x, l), comp) - mass;
	if (right_gran != lev_gran) {
		return lev_gran < right_gran;
	}
	else {
		return (0);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	long int q;
	//Считываем информацию о перевезенных людях в городах.
	//cout << "Введите кол-во городов: ";
	cin >> n;
	for (int z = 0; z < n; z++) {
		cin >> mass[z].chislo_lyd;
		mass[z].index = z + 1;
	}
	sort(mass, mass + n, comp);
	//Обрабатываем q запросов.
	//cout << "Введите количеcтво запросов: ";
	cin >> q;

	vector < long int > otvet(q);
	for (int z = 0; z < q; z++) {
		cin >> l >> r >> x;
		otvet[z] = Poisk_po_zapr(x, l, r);
	}
	for (int z = 0; z < q; z++) {
		cout << otvet[z];
	}

	return 0;
}