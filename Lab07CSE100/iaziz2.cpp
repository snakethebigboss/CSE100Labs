#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash
{
public:
    Hash(int _hashSize);
    virtual ~Hash();

    void Insert(int toInsert);

    // return true if deleted; false if no such key
    bool Delete(int toDelete);

    // return true if found and where; false if not
    bool Search(int key, int &bket, int &pos);

    void Print();

private:
    int hashSize;
    vector<list<int>> table;
};

#endif

Hash::Hash(int _hashSize)
{
    this->hashSize = _hashSize;
    table.resize(_hashSize);
}

Hash::~Hash()
{
}

void Hash::Insert(int toInsert)
{
    int key = toInsert % hashSize;
    table[key].push_front(toInsert);
}

bool Hash::Delete(int toDelete)
{
    list<int>::iterator T;
    int key = toDelete % hashSize;
    list<int> N = table[key];

    if (N.empty())
        return false;

    for (T = table[key].begin(); T != table[key].end(); T++)
    {
        if (toDelete == *T)
        {
            table[key].erase(T);
            return true;
        }
    }

    return false;
}

bool Hash::Search(int key, int &bket, int &pos)
{
    int mod = key % hashSize;
    bket = mod;
    pos = 0;

    list<int>::iterator T;
    list<int> N = table[mod];

    for (T = N.begin(); T != N.end(); T++)
    {

        if (*T == key)
        {
            return true;
        }

        pos++;
    }

    return false;
}

void Hash::Print()
{
    list<int> N;
    list<int>::iterator T;
    for (int i = 0; i < hashSize; i++)
    {
        if (N.empty())
        {
        }
        cout << i << ":";

        N = table[i];
        for (T = N.begin(); T != N.end(); ++T)
        {

            cout << *T << "->";

        }
        cout << ";";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{

    int number = 0;
    bool repeat = true;
    int hashSize;

    string input = "";
    cin >> hashSize;
    Hash table(hashSize);

    do
    {
        number = 0;
        cin >> input;
        //Create integer if required by function
        if (input[0] != 'o' || input[0] != 'e')
        {
            for (int i = 1; i < input.size(); i++)
            {
                int digit = input[i] - '0';
                number = 10 * number + digit;
            }
        }

        if (input[0] == 'i')
        {
            table.Insert(number);
        }
        else if (input[0] == 'd')
        {
            if (table.Delete(number) == true)
                cout << number << ":DELETED;" << endl;
            else
                cout << number << ":DELETE_FAILED;" << endl;
        }
        else if (input[0] == 's')
        {
            int x, y;
            if (table.Search(number, x, y) == true)
                cout << number << ":FOUND_AT" << x << "," << y << ";" << endl;
            else
                cout << number << ":NOT_FOUND;" << endl;
        }
        else if (input[0] == 'o')
        {
            table.Print();
        }
        else if (input[0] == 'e')
        {
            repeat = false;
        }
        else
        {
            cout << "Wrong input" << endl;
        }
    } while (repeat);

    return 0;
}