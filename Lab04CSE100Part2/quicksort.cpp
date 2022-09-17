#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition(int *array, int low, int high)
{
    int pivot = array[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

/* The main function that implements QuickSort 
array[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        /* pindex is partitioning index, array[p] is now 
        at right place */
        int pindex = partition(array, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(array, low, pindex - 1);
        quickSort(array, pindex + 1, high);
    }
}

void printArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << ";";
}

int main()
{
    int arraySize = 0;

    cin >> arraySize;
    int array[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    quickSort(array, 0, arraySize - 1);
    printArray(array, arraySize);

    return 0;
}