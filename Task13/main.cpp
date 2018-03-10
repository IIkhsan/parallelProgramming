//756893125

#include <iostream>
#include <omp.h>
#include <cmath>

int main() {
    int sum = 0;
    int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 30; i++) {
        sum += a[29-i]*pow(2,i);
    }
    return 0;
}