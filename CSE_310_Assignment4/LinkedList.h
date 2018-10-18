// ASU CSE310 Assignment #4
// Name of Author:
// ASU ID:
// Description: LinkedList implements insert,
// deleteStudent, search, displayList and isFound functions.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student
{
    string key;
    string name, gender, inClass_or_onLine, major, campus;
    string status, address, city;
    struct Student *next = NULL;
};

class LinkedList
{
private:
    struct Student *head;
    int size;
public:
    LinkedList();
    ~LinkedList();
    bool insert(string key, string name, string gender, string inClass_or_onLine,
                string major, string campus, string status, string address,
                string city);
    bool deleteStudent(string key);
    bool search(string key);
    void displayList();
    int getSize();
    bool isFound(string key);
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList()
{
    //Add your own codes here
    //----
    //----
}

//Return number of students inside the Linked list
int LinkedList::getSize()
{
    return size;
}

//Insert the parameter student at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insert(string key, string name, string gender, string inClass_or_onLine,
                        string major, string campus, string status, string address, string city)
{
    //Add your own codes here
    //----
    //----
}

//Delete the student with the given key.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteStudent(string key)
{
    //Add your own codes here
    //----
    //----
    if(//the student's key matches the parameter key)
       {
           cout << temp->name << " in "<< temp->major << " major, on "
           << temp->campus << " campus is deleted." << endl;
           //Add your own codes here
           //----
           //----
           return true;
       }
       //----
       //----
       }
       
       //This function searches the student with the given key
       //returns true if it is found, otherwise return false.
       bool LinkedList::search(string key)
    {
        //Add your own codes here
        //----
        //----
    }
       
       //This function displays the content of the linked list.
       //Check the sample output for output format
       void LinkedList::displayList()
    {
        //Add your own codes here
        //----
        //----
    }
       
       //This function searches the Student with the given key inside the linked list.
       //it returns true if it is found and false otherwise.
       bool LinkedList::isFound(string key)
    {
        //Add your own codes here
        //----
        //----
    }
