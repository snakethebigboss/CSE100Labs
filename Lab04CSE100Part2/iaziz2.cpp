#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);     

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pindex = partition(array, low, high);
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