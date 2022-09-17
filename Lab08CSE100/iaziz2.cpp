#include <iostream>

using namespace std;

int size;
int rodSize;

int cutRod(int numbers[], int arr[])
{
    int num[size + 1];
    int last[size + 1];
    num[0] = 0; // no value here
    int i, j;

    for (i = 1; i <= size; i++)
    {
        int efficient = -1;
        int max = -10000000;
        for (j = 0; j < i; j++)
        {
            if (max < numbers[j] + num[i - j - 1])
            {
                efficient = j;
                max = numbers[j] + num[i - j - 1];
            }
        }

        num[i] = max;
        last[i] = efficient + 1;
    }
    i = size;
    j = 0;
    while (i > 0)
    {
        arr[j++] = last[i];
        i -= last[i];
    }
    rodSize = j;
    return num[size];
}

int main()
{

    cin >> size;
    int numbers[size];

    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    int arr[size + 1];

    cout << cutRod(numbers, arr) << endl;
    cout << arr[0];

    for (int i = 1; i < rodSize; i++)
    {
        cout << " " << arr[i];
    }
    cout << " -1\n";
    return 0;
}