#include <omp.h>
#include <stdio.h>

int main() {

    int a[10] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2};
    int b[10] = {10, 2, 3, 4, 5, 1, 5, 4, 3, 2};

    int sum_a = 0, sum_b = 0;
#pragma omp parallel for reduction(+:sum_a) reduction(+:sum_b)
    for (int i = 0; i < 10; i++) {
        sum_a += a[i];
        sum_b += b[i];
    }

    printf("%d %d", sum_a, sum_b);

}