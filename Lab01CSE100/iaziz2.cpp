#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv)
{

    int *Sequence;
    int arraySize = 1;
    int temp;
    int i;
    int j;
    int k;

    // Get the size of the sequence
    cin >> arraySize;
    Sequence = new int[arraySize];

    // Read the sequence
    for (int i = 0; i < arraySize; i++)
    {
        cin >> Sequence[i];
    }

    // Sorting the sequence
    for (int i = 1; i < arraySize; i++)
    {
        temp = Sequence[i]; //key that we will use to compare all the numbers and determine the switching
        j = i;
        while (j > 0 && Sequence[j - 1] > temp) //while loop to compare the numbers, checks if previous number is bigger than key
        {
            Sequence[j] = Sequence[j - 1];
            j--;
        }
        Sequence[j] = temp; //managing the key
        for (int k = 0; k <= i; k++) //printing loop
        {
            cout << Sequence[k] << ";"; 
        }
        cout << endl;
    }
}