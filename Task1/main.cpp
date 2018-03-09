#include <iostream>

int main()
{
#pragma omp parallel num_threads(8)
    {
        printf("Hello! ");
    }
}