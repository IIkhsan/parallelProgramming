#include <omp.h>
#include <stdio.h>

int main() {
    omp_set_num_threads(3);

    #pragma omp parallel if(omp_get_max_threads() > 1)
    {
        printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
    }

    omp_set_num_threads(1);

    if (omp_get_max_threads() > 1)
    {
        #pragma omp parallel if(omp_get_max_threads() > 1)
        {
            printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
        }
    }
}