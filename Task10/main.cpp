#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAGIC 30
#define DIVIDER 9

int main() {

	srand(time(NULL));

	int a[MAGIC];

	int basic_counter = 0;
	for (int i = 0; i < MAGIC; i++){
		a[i] = rand() % MAGIC;
		if (a[i] % DIVIDER == 0) {
			basic_counter++;
		}
	}

	int counter = 0;
	#pragma omp parallel for shared(counter)
	for (int i = 0; i < MAGIC; i++) {
		if (a[i] % DIVIDER == 0) {
			#pragma omp atomic
			counter++;
		}
	}

	printf("counter is %d\n", counter);
	if (basic_counter == counter) {
		printf("the answer is correct\n");
	}

}