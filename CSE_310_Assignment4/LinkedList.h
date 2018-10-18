// ASU CSE310 Assignment #4
// Name of Author: Divesh Basina
// ASU ID: 1205546806
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
    struct Student *temp = head;
    while (temp!=NULL)
    {
        temp=temp->next;
        size = size+1;
    }
    return size;
}

//Insert the parameter student at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insert(string key, string name, string gender, string inClass_or_onLine,
                        string major, string campus, string status, string address, string city)
{
    // Assign memory and create a new student
    Student *new_student = new Student();
    
    // Assign new_student its values
    new_student->key = key;
    new_student->name = name;
    new_student->gender = gender;
    new_student->inClass_or_onLine = inClass_or_onLine;
    new_student->major = major;
    new_student->campus = campus;
    new_student->address=address;
    new_student->city=city;
    
    // Add new_student to the linked list.
    new_student->next = head;
    head = new_student;
    
    // Return
    return true;
}

//Delete the student with the given key.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteStudent(string key)
{
    // Create temporary student.
    struct Student *temp = head;
    struct Student *previous = NULL;
    struct Student *holder = NULL;
    
   // Iterate over the linked list to find the student to delete.
    while (temp->key.compare(key) !=0 )
    {
        previous = temp;
        temp=temp->next;
    }
    
    if(temp->key.compare(key) == 0)
       {
           // Check if we are deleting first node.
           if (previous == NULL)
           {
               head = NULL;
               delete temp;
               
           }
           
           // If we are not deleting the first node
           else
           {
               holder = temp;
               previous->next = temp->next;
               temp=NULL;
               delete holder;
           }
           
           cout << temp->name << " in "<< temp->major << " major, on "
           << temp->campus << " campus is deleted." << endl;
           return true;
       }
    
    else
    {
        cout<< "Student not found" << endl;
        temp = head;
        previous = NULL;
        return false;
    }
}
       
//This function searches the student with the given key
//returns true if it is found, otherwise return false.
bool LinkedList::search(string key)
{
    struct Student *temp = head;
    while (temp->key.compare(key) != 0)
    {
        temp = temp->next;
    }
    
    if (temp->key.compare(key) == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
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
    return true;
}
