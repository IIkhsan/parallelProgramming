//Написать программу, в которой, используя возможности OpenMP найти все простые числа в
//заданном с клавиатуры диапазоне. Количество потоков определить самостоятельно. Результат выдать на экран.
#include <iostream>
#include <omp.h>

int main() {
    int n;
    int m;
    std::cin >> m;
    std::cin >> n;

    int* array = new int [n+m];
    for(int k = 0; k <= n; k++) {
        array[k] = k;
    }
    array[1] = 0;
    //поиск простых
#pragma omp parallel for num_threads(4)
    for(int i = 0; i <=n ; i++) {
        if(array[i] != 0) {
            for(int j = i * 2; j <= n; j += i) {
                array[j] = 0;
            }
        }
    }

    for (int i = m; i <= n ; i++) {
        if (array[i]!=0) {
            std::cout << array [i]<<" ";
        }
    }
    delete [] array;
    return 0;
}