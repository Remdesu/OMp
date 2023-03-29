#include <stdio.h> 
#include <omp.h> 
#include <locale>
#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// k - количество процессов; n - размерность 
	srand(time(0));
        int k, n;
	// id - номер потока
	int i, j, id;
	setlocale(0, "rus");
	cout << "Введите n:" << " ";
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	cout << "Введите количество процессов:" << " ";
	cin >> k;

	omp_set_num_threads(k);
	for (i = 0; i < n; i++)
		// Заполнение случайными числами от 1 до 5
		a[i] = 1 + rand() % 5;
	for (i = 0; i < n; i++)
		// Заполнение случайными числами от 1 до 5
		b[i] = 1 + rand() % 5;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
#pragma omp parallel private(i, id) 
	{
		/* Получим номер текущей нити */
		id = omp_get_thread_num();
		printf("Hello World from thread = %d\n", id);
#pragma omp for 
		for (i = 0; i < n; i++)
		{
			Sleep(1000);
			c[i] = a[i] + b[i];
		}
	}
	cout << "\n";
	for (j = 0; j < n; j++)
	{
		cout << c[j] << " ";
	}
}
