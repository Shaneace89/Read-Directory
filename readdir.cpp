/*File Name: readdir.cpp

 Author: Shane Fleming
 Employer: Texas State University
 Date: 07/26/2019

 Read in from a directory and output first string of each file to .csv*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

/******************************************************************
 menu: displays the main Menu
 couts the main menu, cins users choice (int choice)
 returns: int choice, users decision
 ******************************************************************/

int menu()
{
    int choice = 0;

    cout << "Menu" << endl
         << "1: First 8 Characters of the Filename" << endl
         << "2: Last,First Name (Stops at First '_')" << endl
         << "8: For Custom Amount of Characters" << endl
         << "9: Exit Program" << endl
         << endl
         << "Please enter your choice: ";
     cin >> choice;

     return choice; 
}

/******************************************************************
 dirInput: users directory choice
 couts example, cins users desired directory (string dir)
 returns: string dir, the path to users desired directory
 ******************************************************************/

string dirInput()
{
    string dir;
    cout << endl
         << "Welcome to the Directory Reader" << endl << endl
         << "Example: /home" << endl
         << "Please enter file path: ";
    cin >> dir;
    cout << endl;

    return dir;
}

/******************************************************************
 dirLength: finds length of directory
 takes in string dir, either custom from user or current active
 returns: int count, the number of char in the directory string
 ******************************************************************/

int dirLength(string dirF)
{
    int count = 0;

    for (int i=0; dirF[i]; i++)
        {count++;}
    count++;  //added to remove '/' before filename 
    
    return count;
}

/******************************************************************
 print: creates output.csv file for minor id or custom
 takes in string of the path, the int count of char in path
 takes in charRemove, defaults '8' if choice 8 = custom
 outputs to output.csv stripped file path
 ******************************************************************/

void print(string path, int count, int charRemove)
{
    string print;
    ofstream fout;
    fout.open("output.csv");

    for (const auto & entry : fs::directory_iterator(path))
        {
          print = entry.path();
          print.erase(0,count);
          print.erase(charRemove,100);
          fout << print << endl;
        }
    fout.close();
}

/******************************************************************
 print2: creates output.csv file for last,first name
 takes in string of the path, the int count of char in path
 outputs to output.csv stripped file path (last,first name)
 ******************************************************************/

void print2(string path, int count)
{
    string print;
    ofstream fout;
    fout.open("output.csv");

    for (const auto & entry : fs::directory_iterator(path))
        {
          print = entry.path();
          print.erase(0,count);
          
          print = print.substr(0, print.find("_"));
          fout << print << endl;
        }
    fout.close();
}

/******************************************************************
 main: creates variables, and calls functions, passes need values
 choice 1: found it unnecassary to create funution for
 choice 2: calls dirInput and assigns vaule to dir
 choice catchall: ends program
 calls dirLength and assigns to count
 passes count and dir to print, print cleans and exports
 ******************************************************************/

int main() 
{
    int count = 0, choice, charRemove = 8;
    string dir, path; 

    dir = dirInput();
    choice = menu();

    if (choice == 1)
    {
    count = dirLength(dir);
    print(dir, count, charRemove);

    cout << endl
         << "Directory has been outputted to output.csv"
         << endl << endl;
    }
    else if (choice == 2)
    {
     count = dirLength(dir);
     print2(dir, count);
     
     cout << endl
         << "Directory has been outputted to output.csv"
         << endl << endl;
    }
    else if (choice == 8)
    {
    count = dirLength(dir);
    cout << "How many characters do wish to save? ";
    cin >> charRemove;
    cout << endl;
    print(dir, count, charRemove);

    cout << endl
         << "Directory has been outputted to output.csv"
         << endl << endl;
    }
    else
    {return 0;}
 
    return 0;
}
