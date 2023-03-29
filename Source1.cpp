#include <stdio.h> 
#include <omp.h>
#include <locale>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// k - количество процессов; n - размерность 
	int k, n;
	// id - номер потока
	int i, id;
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
#pragma omp parallel private (id)
	{
		id = omp_get_thread_num();
		for (i = 0; i <= n / k; i++)
			c[i + id * (n / k)] = a[i + id * (n / k)] + b[i + id * (n / k)];
	}

	cout << "\n";
	for (i = 0; i < n; i++)
	{

		cout << c[i] << " ";
	}
}