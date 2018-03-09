#include <iostream>
#include <ctime>
#include "omp.h"

using namespace std;

#define ARRAY 100000
#define RANGE 100000

int a[ARRAY];
void bubble(int a[], int n)
{
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n - i; ++j)
            if(a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

void qsort(int l, int r)
{

    int start = l, end = r;
    int pivot = a[(l + r) / 2];
    while (l < r){
        while (a[l] < pivot) l++;
        while (a[r] > pivot) r--;
        if (l <= r)
        {
            int swap = a[l];
            a[l] = a[r];
            a[r] = swap;
            l++;
            r--;
        }
    }
    if (l < end) qsort(l, end);
    if (start < r) qsort(start, r);
}

void Merge(int l1, int l2, int r1, int r2)
{
    int buffer[ARRAY];
    int current = l1;
    int start = l1, end = r2;
    while (l1 <= l2 && r1 <= r2)
    {
        if (a[l1] < a[r1])
            buffer[current++] = a[l1++];
        else
            buffer[current++] = a[r1++];
    }
    while (l1 <= l2)
        buffer[current++] =a[l1++];
    while (r1 <= r2)
        buffer[current++] = a[r1++];

    for (int i = start; i <= end; ++i)
        a[i] = buffer[i];
}

void MergeSort(int l, int r)
{

    int m = (l+r)/2;
    if (l < r)
    {
        MergeSort(l, m);
        MergeSort(m + 1,r);
    }
    Merge(l, m, m + 1, r);
}

int main(int argc, char* argv[])
{
    clock_t t;

    srand(time(0));
    for (int i = 0; i < ARRAY; ++i) a[i] = rand()%RANGE;

    t = clock();

    omp_set_num_threads(3);
#pragma omp parallel firstprivate(a)

    {

        if(omp_get_thread_num() == 1)
        {
            bubble(a, ARRAY);
            t = clock() - t;
            cout <<(float)t/CLOCKS_PER_SEC << " Bubble sort \n";
        }


        if(omp_get_thread_num() == 2)
        {
            MergeSort(0, ARRAY - 1);
            t = clock() - t;
            cout <<(float)t/CLOCKS_PER_SEC << " Merge sort\n";
        }


        if(omp_get_thread_num() == 0)
        {
            qsort(0,ARRAY -1);
            t = clock() - t;
            cout <<(float)t/CLOCKS_PER_SEC << " Quick sort\n";
        }
    }
    return 0;
}