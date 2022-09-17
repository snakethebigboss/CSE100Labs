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

    // return true if the key is deleted; false, if there is no such key
    bool Delete(int toDelete);

    // return true if key is found and corresponding position; false, otherwise
    bool Search(int key, int &bket, int &pos);

    void Print();

private:
    int hashSize;
    vector<list<int>> table;
};

#endif


Hash::Hash(int _hashSize) {
    this->hashSize = _hashSize;
    table.resize(_hashSize);
}

Hash::~Hash() {
}

void Hash::Insert(int toInsert) {
    int key = toInsert % hashSize;
    //h(k) = k mod m
    table[key].push_front(toInsert);
    //Key is put at the beggining of the link list for collisions
}

bool Hash::Delete(int toDelete) {
    list<int>::iterator T;
    int key = toDelete % hashSize;
    // list<int> N=table[key];
    //  list<int>::iterator i = table[key];
   // int mod = key%size;
    list<int> N=table[key];
    //case 1
    if(N.empty())
        return false; //list empty means delete failed
   //case 2
    for (T = table[key].begin(); T != table[key].end(); T++) //search the list for key
    {
        if(toDelete==*T)
        {
            //print when found
            table[key].erase(T);
            //IF DELETE SUCCESSFUL
            return true;
        }
    }
    
    return false;
}

bool Hash::Search(int key, int& bket, int& pos)
{
    int mod = key % hashSize;
    bket = mod;
    pos = 0;

    list<int>::iterator T;
    list<int> N=table[mod];
   
    for(T = N.begin(); T != N.end(); T++)
    {
        
        if(*T ==key)
        {
            return true;
        }
        
        pos++;
        //position++
    }
    
    return false;
}

void Hash::Print()
{
    list<int> N;
    list<int>::iterator T;
    //list <int> X;
    for(int i = 0; i < hashSize; i++){
            if(N.empty())
            {}
            cout<< i << " : ";
            //PRINTS LIST
            N=table[i];
            for (T=N.begin(); T!=N.end(); ++T)
            {
                //cout<< *T<<"->";
                cout << *T;
               
                //check if we are on the END, if not,only then can we print ->
                if(++T != N.end())
                    cout << "->";
                    --T;
                
            }
           // cout<<";";
            cout<<endl;
        
    
}

}

int main(int argc, char const *argv[])
{

    int number = 0;
    bool repeat = true;
    int hashSize;
    int key;

    Hash table(hashSize);

    string input = "";
    cin >> hashSize;

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
            table.Insert(key);
        }
        else if (input[0] == 'd')
        {
			if (table.Delete(key) == true) cout << key << " : DELETED" << endl;
			else cout << key << " : DELETE FAILED" << endl;
        }
        else if (input[0] == 's')
        {
            int x, y;
			if (table.Search(key, x, y) == true) cout << key << " : FOUND AT " << x << "," << y << endl;
			else cout << key << " : NOT FOUND" << endl;
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