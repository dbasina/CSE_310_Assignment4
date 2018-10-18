// ASU CSE310 Assignment #4
// Name of Author: Divesh Basina
// ASU ID: 1205546806
// Description: this is where you need to design Hash table functions,
// such as hashInsert, hashDelete, hashSearch and hashDisplay
// ---- is where you need to add your own codes

#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"

using namespace std;

class Hash
{
private:
    LinkedList **table;
    int m;
public:
    Hash(int size);
    ~Hash();
    bool hashInsert(string name, string gender, string inClass_or_onLine,
                    string major, string campus, string status,
                    string address, string city);
    
    bool hashDelete(string name, string gender, string major, string address);
    bool hashSearch(string name, string gender, string major, string address);
    void hashDisplay();
    int h(string key);
    
    //Add any other necessary function declarations here
    //which you think are useful
    //----
    //----
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
    table = NULL;
}

//hashInsert inserts a student with the relevant info. into the hash table.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string name, string gender, string inClass_or_onLine,
                      string major, string campus, string status,
                      string address, string city)
{
    //Add your own codes here
    //----
    //----
}

//hashDelete deletes a student with the relevant key from the hash table.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of name, gender, major and address
bool Hash::hashDelete(string name, string gender, string major, string address)
{
    //A bool variable used to check whether the student is deleted from
    //the hash table or not.
    bool deleted = false;
    
    //Add your own codes here
    //----
    //----
    
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
    
    //Add your own codes here
    //----
    //----
    
    if(found == false)
        cout << name << " with "<< major << " major, live at "
        << address << " is not found." << endl;
    return found;
}

//This function prints all students from the hash table.
//check our sample output for the format
void Hash::hashDisplay()
{
    //Add your own codes here
    //----
    //----
}

//This is the hash function you will design and use
//put clear comments here to let us know what kind of
//hash function did you use
//Hush function description:
//----
//----
int Hash::h(string key)
{
    //Add your own codes here
    //----
    //----
}
