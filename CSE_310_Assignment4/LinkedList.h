// ASU CSE310 Assignment #4
// Name of Author: Divesh Basina
// ASU ID: 1205546806
// Description: LinkedList implements insert,
// deleteStudent, search, displayList and isFound functions.
#include <iomanip> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string key;
    string name, gender, inClass_or_onLine, major, campus;
    string status, address, city;
    struct Student *next;
};

class LinkedList
{
public:
    struct Student *head;
    int size;
    LinkedList();
    ~LinkedList();
    bool insert(string key, string name, string gender, string inClass_or_onLine,
                string major, string campus, string status, string address,
                string city);
    bool deleteStudent(string key);
    bool search(string key);
    void displayList();
    int getSize();
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
    Student *temp = head;
    Student *del = NULL;
    while(temp!=NULL)
    {
        del = temp;
        temp = temp->next;
        delete del;
        del = NULL;
    }
}

//Return number of students inside the Linked list
int LinkedList::getSize()
{
    struct Student *temp;
    temp = head;
    while (temp != NULL)
    {
        size = size+1;
        temp = temp->next;
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
    new_student->next = NULL;
    
    // Insert at the beginning
    new_student->next = head;
    head = new_student;
    size=size+1;
    
    // Return
    return true;
}

//Delete the student with the given key.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteStudent(string key)
{
    // Create temporary student.
    struct Student *temp = head;
    string del_name,del_major,del_campus;
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
           // Store the name, major and campus for later
           del_name = temp->name;
           del_campus = temp->campus;
           del_major = temp->major;
           // Check if we are deleting first node.
           if (previous == NULL)
           {
               head = head->next;
               delete temp;
               temp = NULL;
               
           }
           
           // If we are not deleting the first node
           else
           {
               holder = temp;
               previous->next = temp->next;
               temp=NULL;
               delete holder;
           }
           
           cout << del_name << " in "<< del_major << " major, on "
           << del_campus << " campus is deleted." << endl;
           size=size-1;
           // Restore default values after delete
           del_name ="";
           del_major="";
           del_campus="";
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
bool LinkedList::search(string key_input)
{
    struct Student *temp = head;
    
    while (temp!=NULL)
    {
        if ((temp->key).compare(key_input)==0)
        {
            return true;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    
    return false;
}
       
       //This function displays the content of the linked list.
       //Check the sample output for output format
void LinkedList::displayList()
{
    struct Student *temp = head;
    while(temp!= NULL)
    {
        cout<<"Name:\t\t"<< temp->name <<endl;
        cout<<"Gender:\t\t"<< temp->gender <<endl;
        cout<<"inClassOrOnline:\t\t"<< temp->inClass_or_onLine <<endl;
        cout<<"Major:\t\t"<<temp->major<<endl;
        cout<<"Campus:\t\t"<<temp->campus<<endl;
        cout<<"Address:\t\t"<<temp->address<<endl;
        cout<<"City:\t\t"<<temp->city<<endl;
        cout<<"\n"<<endl;
        temp = temp->next;
        
    }
}
