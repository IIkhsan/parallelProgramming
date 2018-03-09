#include <iostream>
#include <cmath>

typedef double(*function)(double);

double integral(function f, double a, double b, unsigned step_count) {
    double sum = .0, step;
    size_t i;
    if (0 == step_count) return sum;
    step = (b - a) / (1.0 * step_count);
#pragma omp parallel for shared(sum, step) ordered
    for ( i = 1 ; i < step_count ; ++i ) {
#pragma omp ordered
        sum += f (a + i * step);
    }
    sum += (f(a) + f(b)) / 2;
    sum *= step;
    return sum;
}

double f(double x) {
    return 4 / (1 + pow(x, 2));
}

int main() {
    printf("%f", integral(f, 0, 1, 15));
    return 0;
}