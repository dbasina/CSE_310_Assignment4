// ASU CSE310 Assignment #4
// Name of Author: Divesh Basina
// ASU ID: 1205546806
// Description: this is where you need to design Hash table functions,
// such as hashInsert, hashDelete, hashSearch and hashDisplay
// ---- is where you need to add your own codes

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "LinkedList.h"

using namespace std;

class Hash
{
    LinkedList **table;
    int m;
    Hash(int size);
    ~Hash();
    bool hashInsert(string name, string gender, string inClass_or_onLine,
                    string major, string campus, string status,
                    string address, string city);
    
    bool hashDelete(string name, string gender, string major, string address);
    bool hashSearch(string name, string gender, string major, string address);
    void hashDisplay();
    int h(string key);
    int nearestPrime(int table_size);
};

//constructor - create an array of LinkedList, m is the number of slots
Hash::Hash(int size)
{
    table = new LinkedList*[size];
    m = size;
}

//Destructor - release the memory
Hash::~Hash()
{
    delete[] table;
    table = nullptr;
}

//hashInsert inserts a student with the relevant info. into the hash table.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string name, string gender, string inClass_or_onLine,
                      string major, string campus, string status,
                      string address, string city)
{
    // Create string key
    string key = name + gender + major + address;
    // Convert string key to numeric key
    // Access the pointer to the linked list at table[h(k)] and insert
    if(table[h(key)] == nullptr)
    {
        table[h(key)] = new LinkedList();
    }
        
    table[h(key)] -> insert(key,name,gender,inClass_or_onLine,major,campus,status,address,city);
    return true;
}

//hashDelete deletes a student with the relevant key from the hash table.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of name, gender, major and address
bool Hash::hashDelete(string name, string gender, string major, string address)
{
    //A bool variable used to check whether the student is deleted from
    //the hash table or not.
    bool deleted = false;
    string key = name + gender + major + address;
    
    if(table[h(key)]->search(key))
    {
        table[h(key)]->deleteStudent(key);
        deleted= true;
    }
    if(!deleted)
    {
        cout << name << " with "<< major << " major, live at "
        << address << " is not found." << endl;
    }
    return deleted;
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of name, gender, major and address
bool Hash::hashSearch(string name, string gender, string major, string address)
{
    //A bool variable used to check whether the student is found
    //inside the hash table or not.
    bool found = false;
    string key = name + gender + major + address;
    
    if (table[h(key)]->search(key))
    {
        found = true;
    }
    
    if(found == false)
        cout << name << " with "<< major << " major, live at "
        << address << " is not found." << endl;
    return found;
}

//This function prints all students from the hash table.
//check our sample output for the format
void Hash::hashDisplay()
{
    int i=0;
    
    while (i<m)
    {
        if ( table[i] == nullptr )
        {
            continue;
        }
        
        else
        {
            cout<<"index:\t"<<i<<"\tlinked list size:\t"<< table[i]->size <<endl;
            table[i]->displayList();
        }
        i = i+1;
    }
    
}


//Hash function description:
// Using hash by division where the key is converted into radix notation using base 128.
// h(k) = key % nearestPrime(m);
int Hash::h(string key)
{
    long double key_val=0;
    long double hash_val;
    for (int i=0; i< (int)key.length() ; i++)
    {
        int exponent = ((int)key.length())-(i+1);
        key_val = key_val + ( ( pow( (long double) 128, (long double) exponent) ) * (key[i]) );
    }
    hash_val = (int)fmod(key_val, nearestPrime(m));
    return  hash_val;
}

// This method is used to compute the nearest prime number to table_size. Used in the hash function above.
int Hash::nearestPrime(int table_size)
{
    int prime = table_size;
    int i=2;
    while (i<prime)
    {
        if (prime % i == 0)
        {
            i= i+1;
            prime = prime - 1;
        }
        
        else
        {
            i++;
        }
    }
    
    return prime;
    
}
