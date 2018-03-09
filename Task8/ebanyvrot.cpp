//
// Created by Ilyas on 09.03.18.
//
#include <iostream>
#include <omp.h>

int main(){
    int matrix[100][100], // статический массив
            rows    = 2,      // строки
            columns = 4;      // столбцы

    // заполнение матрицы
    for (int ix = 0; ix < rows; ix++ )
        for (int jx = 0; jx < columns; jx++)
        {
            matrix[ix][jx] = ix+1;
        }

    int vector[100]; // вектор

    // заполнение вектора
    for (int ix = 0; ix < columns; ix++ )
    {
        vector[ix] = ix;
    }

    for (int ix = 0; ix < rows; ix++ )
    {
        for (int jx = 0; jx < columns; jx++)
        {
            printf("%d",matrix[ix][jx]);
        }
        printf("\n");
    }

    for (int ix = 0; ix < columns; ix++ )
    {
        printf("%d",vector[ix]);
    }

    int out[100]; // выходной вектор
    // умножение элементов матрицы на вектор
    double start = omp_get_wtime();
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }

    double end = omp_get_wtime();
    double time = end - start;
    
    double parallel_start = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 4) num_threads(4)
    for (int ix = 0; ix < rows; ++ix) {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++) {
            out[ix] = matrix[ix][jx] * vector[jx];
        }
    }
    double parallel_end = omp_get_wtime();
    double parallel_time = parallel_end - parallel_start;

    printf("\nПоследовательно время: %lf, паралельное: %lf", parallel_time, time);
    for(int ix = 0; ix < rows; ix++){
        printf("\n%d",out[ix]);
    }
    return 0;
}

