#include <iostream>
#include <omp.h>

int main() {
    int n, s;
    n = 210, s = 0;
    omp_set_num_threads(6);

#pragma omp parallel for reduction(+: s)
    for (int i = 0; i < n; i++) {
        s += n;
    }

    printf("%d",s);
    return 0;
}