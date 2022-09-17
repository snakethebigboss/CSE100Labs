#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void countSort(vector<int> array[], int vecamount, int p)
{
    vector<int> *output;
    output = new vector<int>[vecamount];

    int i; 
    int count[10] = {0};

    for (i = 0; i < vecamount; i++)
    {
        count[array[i][p] % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = vecamount - 1; i >= 0; i--)
    {
        output[count[array[i][p] % 10] - 1] = array[i];
        count[array[i][p] % 10]--;
    }

    for (i = 0; i < vecamount; i++)
    {
        array[i] = output[i];
    }
}

void radixsort(vector<int> array[], int vecamount)
{
    for (int p = 9; p >= 0; p--) 
    {
        countSort(array, vecamount, p);
    }
}

int main()
{
    int vecamount;
    cin >> vecamount;
    vector<int> *array;
    array = new vector<int>[vecamount];

    for (int i = 0; i < vecamount; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int n;
            cin >> n;
            array[i].push_back(n); //puts values into vectors
        }
    }

    radixsort(array, vecamount);

    for (int i = 0; i < vecamount; i++) //loop to print out sorted vectors
    {
        for (vector<int>::iterator output = array[i].begin(); output != array[i].end(); output++)
        {
            cout << *output << ";";
        }
        cout << endl;
    }

    return 0;
}