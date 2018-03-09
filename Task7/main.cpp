#include <omp.h>
#include <stdio.h>

#define MAGIC 12

int main() {

	int a[MAGIC], b[MAGIC], c[MAGIC];

#pragma omp parallel num_threads(3)
	{
		#pragma omp for schedule(static, 1)
		for (int i = 0; i < MAGIC; i++) {
			a[i] = i * 2;
			b[i] = i * 3;
			printf("working %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		}
	}

	for (int i = 0; i < MAGIC; i++) {
		printf("%d ", a[i]);
	} printf("\n");

	for (int i = 0; i < MAGIC; i++) {
		printf("%d ", b[i]);
	} printf("\n");


#pragma parallel omp for schedule(dynamic, 2) num_threads(4)
		for (int i = 0; i < MAGIC; i++) {
			c[i] = a[i] + b[i];
			printf("working %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		}

		for (int i = 0; i < MAGIC; i++) {
			printf("%d ", c[i]);
		} printf("\n");



}