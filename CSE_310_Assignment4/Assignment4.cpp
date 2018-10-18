// ASU CSE310 Assignment #4
// Name of Author:
// ASU ID:
// Description: this is the main program that reads input from a text file,
// it then call hash functions to execute hash commands given in the input.

/**************************************************************************
 //(1)Describe here what is your hash function? How do you get an input
 // data's hash value.
 //(2)What is the number of collisions you expected?
 //(3)Did your hash function work well? Using the test cases, what's your hash
 //   table's load factor?
 //(4)If you had to change your hash function to reduce the number of collisions,
 //   how will you change it?
 //----
 //----
 ***************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "Hash.h"

using namespace std;

int main()
{
    string name, gender, inClass_or_onLine, major, campus,
    status, address, city;
    
    //a variable represents the number of hash table slots
    int count;
    
    //a variable represents the number of commands inside the input file
    int numOfCommand;
    
    //a variable represents the actual command name inside the input file
    string command;
    
    //declare any other necessary variables here
    //----
    
    //get the first line which is a number and store it inside count
    cin >> count;
    
    //create a hash table with the 'count' number of slots
    //----
    do
    {
        //get one line of student data
        //----
        //Tokenize it to get each information out, then
        //insert the new student inside the hash table
        //----
        //----
    } while(//as long the line we read in is not "InsertionEnd");
            
            cin >> numOfCommand;
            for(int i= 0;i < numOfCommand; i++)
            {
                //Get each line of the command
                //Tokenize it to extract the information
                //----
                switch (command)
                {
                    case "hashDisplay": //Add your own codes to handle the case
                        //----
                        break;
                    case "hashSearch": //Add your own codes to handle the case
                        //----
                        break;
                    case "hashDelete": //Add your own codes to handle the case
                        //----
                        break;
                    default:            cout<<"Invalid command" << endl;
                        break;
                }//end switch
            }//end for
            return 0;
            }
