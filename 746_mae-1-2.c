#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;

const int n = 100;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "Сотрировка Шелла: \n";
	cout << "Количество элементов: " << n << endl;
	int arr[n] = {};
	int srav, peres, globsrav = 0, globperes = 0;
	clock_t start;
	double stop;
	double globstop = 0;
	int i, j, step, tmp, t;
	for (int h = 1; h <= 100; h++) {
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 2001 - 1000;
		}
		srav = 0; peres = 0; stop = 0;
		start = clock();
		for (step = n / 2; step > 0; step /= 2) {
			for (i = step; i < n; i++)
			{
				tmp = arr[i];
				if (i <= step) srav++;
				for (j = i; j >= step; j -= step)
				{
					srav += 1;
					if (tmp < arr[j - step]) {
						arr[j] = arr[j - step];
						peres += 1;
					}
					else
						break;
				}
				arr[j] = tmp;
			}
		}
		stop = (clock() - start) / (double)CLOCKS_PER_SEC;
		globstop += stop;
		globsrav += srav;
		globperes += peres;
	}
	cout << "Среднее количество перестановок: " << globperes/100 << endl;
	cout << "Среднее количество сравнений: " << globsrav/100 << endl;
	printf("Срденее время сортировки: %.10f", globstop/100);
	_getch();
	return 0;
}

