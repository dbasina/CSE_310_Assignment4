// ASU CSE310 Assignment #4
// Name of Author: Divesh Basina
// ASU ID: 1205546806
// Description: this is the main program that reads input from a text file,
// it then call hash functions to execute hash commands given in the input.

/**************************************************************************
 //(1)Describe here what is your hash function?
 // Hash Function uses radix notation with base 128 to convert string to a number.
 // Then I use the closest prime number to m to calculate a hash value using the modulo
 // operator.
 //(2)What is the number of collisions you expected?
 // 6
 //(3)Did your hash function work well? Using the test cases, what's your hash
 //   table's load factor?
 // Given the size of the table and input,
 // The test cases are too small for my hash function to be effective.
 // maximum load factor i got was 8
 //(4)If you had to change your hash function to reduce the number of collisions,
 // I would implement a randomization algorithm to randomize the number of letters
 // And also the letters I pick from the string key that is given, where the max for number
 // of letters is the length of the string, where each letter is picked at random.
 // then I would use a radix notation using a prime number as base to convert this alphabetic
 // key to a numeric key. On this key, I would implement a double hashing algorithm where,
 // my first hashing function is a linear function and the second hashing function
 // a quadratic. The value of m will still be the closest prime number to the table size.
 ***************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include "Hash.h"

using namespace std;

int main()
{
    string name, gender, inClass_or_onLine, major, campus,
    status, address, city;
    
    string input_termination ="InsertionEnd";
    //a variable represents the number of hash table slots
    int count;
    
    //a variable represents the number of commands inside the input file
    int numOfCommand;
    
    
    //a variable represents the actual command name inside the input file
    string command;
    string data;
    string str_count;
    string str_numOfCommand;
    bool insertion = false;
    //declare any other necessary variables here
    //get the first line which is a number and store it inside count
    getline(cin, str_count);
    count = std::stoi(str_count);
    
    // initialize hash table.
    Hash *hash_table = new Hash(count);
    
    // use while loop to iterate and insert data.
    getline(cin,data);
    while(data.compare(input_termination)!=0)
    {
        string data_array[8];
        
        istringstream f(data);
        string s;
        
        int i=0;
        while (getline(f, s,','))
        {
            data_array[i] = s;
            i=i+1;
        }
        insertion = hash_table->hashInsert(data_array[0], data_array[1], data_array[2], data_array[3], data_array[4], data_array[5], data_array[6], data_array[7]);
        getline(cin,data);
    }
    
    // Get number of commands and iterate over commands.
    getline(cin,str_numOfCommand);
    numOfCommand = stoi(str_numOfCommand);
    for(int i= 0;i < numOfCommand; i++)
    {
        string command_array[5];
        getline(cin,command);
        istringstream f(command);
        string s;
        
        int j=0;
        while (getline(f, s, ','))
        {
            command_array[j] = s;
            j=j+1;

        }
        
        // Recognize and execute the command on the hashtable
        if (command_array[0].compare("hashDisplay")==0)
        {
            hash_table->hashDisplay();
            
        }
            
        else if (command_array[0].compare("hashSearch")==0)
        {
            bool found = hash_table->hashSearch(command_array[1], command_array[2], command_array[3], command_array[4]);
            if(found)
            {
                cout << command_array[1] << " with "<< command_array[3] << " major, live at "<< command_array[4] << " is found." << endl;
            }
        }
            
        else if (command_array[0].compare("hashDelete")==0)
        {
            hash_table->hashDelete(command_array[1], command_array[2], command_array[3], command_array[4]);
        }
            
        else
        {
            cout<<"Invalid command" << endl;
        }
        }
    

    return 0;
}
