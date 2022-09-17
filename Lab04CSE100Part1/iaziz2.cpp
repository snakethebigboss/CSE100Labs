#include <iostream>
 
using namespace std;
 
void heaptree(int *array, int arraySize, int i)
{
    int largest = i; // root
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
 
    if (left < arraySize && array[left] > array[largest])
        largest = left;
 
    if (right < arraySize && array[right] > array[largest])
        largest = right;
 
    if (largest != i) {
        swap(array[i], array[largest]);
        heaptree(array, arraySize, largest);
    }
}
 
void heapSort(int *array, int arraySize)
{
    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heaptree(array, arraySize, i);
 
    for (int i = arraySize - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heaptree(array, i, 0);
    }
}
 
void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
        cout << array[i] << ";";
}
 
int main()
{
    int arraySize = 0;
    int answer;

    cin >> arraySize;
    int array[arraySize]; 

    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }
 
    heapSort(array, arraySize);
    printArray(array, arraySize);
}