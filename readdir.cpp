/*File Name: readdir.cpp

 Author: Shane Fleming
 Employer: Texas School Safety Center
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

    cout << endl
         << "Welcome to the Directory Reader" << endl
         << endl
         << "1: Output Current Directory to output.csv" << endl
         << "2: Output Custom Directory to output.csv" << endl
         << "3: Exit Program" << endl
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
    
    cout << "Example: /home" << endl << endl
         << "Please enter file path: ";
    cin >> dir;
    cout << endl << endl
         << "Directory has been outputted to output.csv"
         << endl << endl;

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
 print: creates output.csv file
 takes in string of the path, the int count of char in path
 outputs to output.csv stripped file path (only file name)
 ******************************************************************/

void print(string path, int count)
{
    string print;
    ofstream fout;
    fout.open("output.csv");

    for (const auto & entry : fs::directory_iterator(path))
        {
          print = entry.path();
          print.erase(0,count);
          print.erase(8,100); //8 needs to be a variable
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
    int count = 0, choice;
    string dir, path; 

    choice = menu();

    if (choice == 1)
    {
    dir = fs::current_path();

    cout << endl
         << "Directory has been outputted to output.csv"
         << endl << endl;
    }
    else if (choice == 2)
    {
      dir = dirInput();
    }
    else
    {return 0;}

    count = dirLength(dir);
    print(dir, count);  
 
    return 0;
}
