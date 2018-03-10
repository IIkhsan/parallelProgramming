#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAGIC 300
#define DIVIDER 7

int main() {

	srand(time(NULL));

	int a[MAGIC];

	int base_max = -1;
	for (int i = 0; i < MAGIC; i++){
		a[i] = rand() % MAGIC;
		if (a[i] % DIVIDER == 0 && base_max < a[i]) {
			base_max = a[i];
		}
	}

	int max = -1;
	#pragma omp parallel for shared(max)
	for (int i = 0; i < MAGIC; i++) {
		if (a[i] % DIVIDER == 0 && max < a[i]) {
			#pragma omp critical
			{
				max = a[i];
			}
		}
	}

	printf("%d\n", max);
	if (base_max == max) {
		printf("correct\n");
	}
}