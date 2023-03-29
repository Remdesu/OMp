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
	// id - номер потока
	int i, id, n, a, t;
	// t - счетчик
	t = 0;
	a = 0;
	omp_set_num_threads(6);
#pragma omp parallel private (id) shared (a,t)
	{
		n = omp_get_num_threads();
		id = omp_get_thread_num();
		printf("%d ", id);
		while (t != id) {}
		a += n - id;
		t += 1;
	}
	cout << "\n";
	cout << "a = " << a;
}