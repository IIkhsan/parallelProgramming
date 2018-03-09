#include <iostream>
#include <iomanip>
#include <omp.h>

int main() {
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
#pragma omp parallel for
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }

    printf("\nрезультирующий вектор:\n");
    for (int ix = 0; ix < rows; ix++ )
    {
        printf("%d\n",out[ix]);
    }


    return 0;
}