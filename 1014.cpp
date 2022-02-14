#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//Функция получения числа Q
void Ymnozhenie(long int ishodnoe_chislo, int* numbers) { 

	for (int i = 9; i > 1; --i) {
		numbers[i] = 0;
		while (ishodnoe_chislo % i == 0) {
			ishodnoe_chislo = ishodnoe_chislo/i;
			numbers[i]++;
		}
	}

	if (ishodnoe_chislo == 1) {
		for (int i = 2; i <= 9; ++i) {
			while (numbers[i]) {
				numbers[i]--;
				printf("%d", i);
			}
		}
	}
	else printf("%d", -1);
}

int main() {

	setlocale(LC_ALL, "Rus");

	long int N;
	//printf("Введите число N: ");
	scanf_s("%ld", &N);
	int n = 10;

	int* numbers = (int*)malloc(n* sizeof(int));

	//printf("Число Q: ");

	if (N == 0) {
		printf("%d", 10);
		return 0;
	}

	if (N == 1) {
		printf("%d", 1);
		return 0;
	}
	Ymnozhenie(N, numbers);

	free(numbers);

	return 0;
}