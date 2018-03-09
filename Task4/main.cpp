#include <omp.h>
#include <stdio.h>

int main() {

    int a[10] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2};
    int b[10] = {10, 2, 3, 4, 5, 1, 5, 4, 3, 2};

    int max = 0;
    int min = 0;

#pragma omp parallel sections num_threads(2)
    {
#pragma omp section
        {
            min = a[0];
            for (int i = 0; i < 10; i++) {
                if (min > a[i]) { min = a[i]; }
            }
        }

#pragma omp section
        {
            max = b[0];
            for (int i = 0; i < 10; i++) {
                if (max < b[i]) { max = b[i]; }
            }
        }
    }

    printf("Min in array a %d, max in array b %d\n", min, max);

}