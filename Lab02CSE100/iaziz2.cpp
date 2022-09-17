#include <iostream>
using namespace std;

void merge(int *array, int left, int mid, int right)
{
    int i; 
    int j; 
    int k; 
    int nl; 
    int nr;
    //size of left and right sub-arrays
    nl = mid - left + 1;
    nr = right - mid;
    int leftarr[nl], rightarr[nr];
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        leftarr[i] = array[left + i];
    for (j = 0; j < nr; j++)
        rightarr[j] = array[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    //merge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (leftarr[i] <= rightarr[j])
        {
            array[k] = leftarr[i];
            i++;
        }
        else
        {
            array[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { //extra element in left array
        array[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < nr)
    { //extra element in right array
        array[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int left, int right)
{
    int mid;
    if (left < right) // must check or else it will keep dividing and break self
    {
        int mid = left + (right - left) / 2;
        // Sort first and second arrays
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void printFunc(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cout << array[i] << ";";
}

int main()
{
    int arraySize = 0;

    cin >> arraySize;
    int array[arraySize]; //create an array with given number of elements

    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    mergeSort(array, 0, arraySize - 1); //(arraySize-1) for last index
    printFunc(array, arraySize);
}