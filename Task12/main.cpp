#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAGIC 30

int main() {

    int width = 6;
    int height = 8;

    int d[width][height];
    srand(time(NULL));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            d[i][j] = rand() % MAGIC;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
#pragma omp parallel for ordered
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
#pragma omp ordered
            printf("%d ", d[i][j]);

        }
        printf("\n");
    }

    int max = -1;
    int min = MAGIC + 1;

    int counter = 0;
#pragma omp parallel num_threads(6) reduction(+: counter)
    for (int i = 0; i < width; i++) {
#pragma omp for
        for (int j = 0; j < height; j++) {
            counter++;
            if (min > d[i][j]) {
#pragma omp critical
                min = d[i][j];
            }
            if (max < d[i][j]) {
#pragma omp critical
                max = d[i][j];
            }
        }
    }
    printf("counter is %d\n", counter);
    printf("max is %d, min is %d\n", max, min);

}
//я не нашел решения для этой задачи с помощью параллельного программирования