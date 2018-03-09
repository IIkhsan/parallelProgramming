//#include <cstdio>
#include "iostream"
#include "omp.h"
using namespace std;

#define N 100000

int main() {
    double start, end;
    start = omp_get_wtime();

    float* a = new float[N];
    float* b = new float[N];
#pragma omp parallel for shared(a,b)
    for (int i = 0; i < 1000; i++)
    {
        a[i], b[i] = rand();
    }
    float s = 0;
#pragma omp parallel
    for (int i = 0; i < 1000; i++)
    {
        s += a[i] * b[i];
    }
    end = omp_get_wtime();
    printf("time = %f \n", end - start);
    printf("s=%f \n", s);

    return 0;
}
