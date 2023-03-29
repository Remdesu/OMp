#include <stdio.h> 
#include <omp.h> 
#include <locale>
int main()
{
	int potok, chislo;
	omp_set_num_threads(4);
#pragma omp parallel private (potok) 
	{
		chislo = omp_get_num_threads();
		potok = omp_get_thread_num();
		printf("Hello World from thread = %d\n", potok);
	}
	printf("Number of threads = %d\n", chislo);
}
