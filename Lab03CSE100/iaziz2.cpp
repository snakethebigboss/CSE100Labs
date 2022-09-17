#include <iostream>
using namespace std;
#include <climits>

int DivideAndConquer(int *array, int size)
{
    int max = INT_MIN;
    int newmax = 0;
    int start = 0;
    int end = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++)
    {
        newmax += array[i]; //adds them together

        if (max < newmax) // looking for largest number
        {
            max = newmax;
            start = j;
            end = i;
        }

        if (newmax < 0)
        {
            newmax = 0;
            j = i + 1;
        }
    }
    return max;
}

int main()
{
    int arraySize = 0;
    int answer;

    cin >> arraySize;
    int array[arraySize]; //create an array with given number of elements

    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    answer = DivideAndConquer(array, arraySize);
    cout << answer;
    return 0;
}