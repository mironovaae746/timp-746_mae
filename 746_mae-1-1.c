#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 10;
const double fm = 1.2473309;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "Сотрировка расчёской: \n";
	cout << "Количество элементов: " << n << endl;
	int arr[n] = {};
	int globsrav = 0, globperen = 0, srav, peren;
	clock_t start;
	double stop;
	double globstop = 0;
	for (int y = 1; y <= 100; y++) {
		srav = 0; peren = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 2001 - 1000;
		}
		start = clock();
		int s = n / fm, t;
		while (s >= 1) {
			for (int i = 0; i + s < n; i++) {
				srav += 1;
				if (arr[i] > arr[i + s]) {
					t = arr[i];
					arr[i] = arr[i + s];
					arr[i + s] = t;
					peren += 1;
				}
			}
			s /= fm;
		}
		int l, k, n1 = n;
		while (n1 > 1) {
			k = 0;
			for (int i = 1; i < n; ++i) {
				srav += 1;
				if (arr[i] < arr[i - 1]) {
					l = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = l;
					k = i;
					peren += 1;
				}
			}
			n1 = k;
		}
		stop = (clock() - start) / (double)CLOCKS_PER_SEC;
		globstop += stop;
		globperen += peren;
		globsrav += srav;
	}
	cout << endl;
	cout << "Среднее количество перестановок: " << globperen / 100 << endl;
	cout << "Среднее количество сравнений: " << globsrav / 100 << endl;
	printf("Срденее время сортировки: %.10f", globstop / 100);
	_getch();
	return 0;
}

