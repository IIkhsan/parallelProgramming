#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAGIC 30

int main() {

    int d[6][8];
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % MAGIC;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

#pragma omp parallel sections
    {
#pragma omp section
        {
            int elements = 0;
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    sum += d[i][j];
                    elements++;
                }
            }
            printf("mid is %.2f from %d thread\n", sum * 1.0 / elements, omp_get_thread_num());
        }

#pragma omp section
        {
            int max = d[0][0];
            int min = d[0][0];
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (min > d[i][j]) {
                        min = d[i][j];
                    }
                    if (max < d[i][j]) {
                        max = d[i][j];
                    }
                }
            }
            printf("max is %d and max is %d from %d thread\n", max, max, omp_get_thread_num());
        }

#pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (d[i][j] % 3 == 0) {
                        sum += d[i][j];
                    }
                }
            }
            printf("sum of deviders is %d from %d thread\n", sum, omp_get_thread_num());
        }
    }

}