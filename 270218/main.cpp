#include <iostream>
#include <omp.h>


//omp_get_thread_num() - номер нити
//omp_get_num_threads() - общее число нитей

//2. #pragma omp parallel if () - параллельная секция

//3. #pragma omp parallel firstprivate(i) - локальные копии будут иметь значение значения на входе
//3. #pragma omp parallel lastprivate - переменная будет иметь типо последнего полученного значения например в цикле

//4 и 5. максимум считает одна нить а минимум вторая нить #pragma omp section и sections

//



int main() {
    std::cout << "Hello, World!" << std::endl;
    int a = omp_get_thread_num();
    int b = omp_get_num_threads();
    return 0;
}