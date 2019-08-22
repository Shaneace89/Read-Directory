/*File Name: readdir.cpp

 Author: Shane Fleming
 Employer: Texas State University
 Date: 07/26/2019

 Read in from a directory and output first string of each file to .csv*/

#include "readdir.h"

using namespace std;
namespace fs = experimental::filesystem;

/******************************************************************                                              
DirectoryExists: checks if dir is valid path
takes in dir, as dir path
returns bool, true if valid, false if not found
******************************************************************/

bool DirectoryExists(const char* pzPath)
{
    if ( pzPath == NULL) return false;

    DIR *pDir;
    bool bExists = false;

    pDir = opendir (pzPath);

    if (pDir != NULL)
    {
        bExists = true;    
        (void) closedir (pDir);
    }

    return bExists;
}

/******************************************************************
 menu: displays the main Menu
 couts the main menu, cins users choice (int choice)
 returns: int choice, users decision
 ******************************************************************/

int menu()
{
    int choice = 0;

    cout << "Menu" << endl
         << "1: Filename until first '_'" << endl
         << "2: Filename until first '-'" << endl
         << "3: Filename until first '.'" << endl
         << "4: Filename until first ','" << endl
         << "5: Filename until first ':'" << endl
         << "6: Filename until first ' '" << endl
         << "7: Filename until first custom character" << endl
         << "8: Finename until custom count" << endl
         << "9: Exit Program" << endl
         << "0: Display (cat) output.csv" << endl
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
         << "Welcome to the Directory Reader"
         << endl << endl
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
 print: creates output.csv file custom amount
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
 print2: creates output.csv file for certain char
 takes in string of the path, the int count of char in path
 outputs to output.csv stripped file path
 ******************************************************************/

void print2(string path, int count, char dot)
{
    string print;
    ofstream fout;
    fout.open("output.csv");

    for (const auto & entry : fs::directory_iterator(path))
        {
          print = entry.path();
          print.erase(0,count);
          
          print = print.substr(0, print.find(dot));
          fout << print << endl;
        }
    fout.close();
}

/******************************************************************
 printy: displays text
 ******************************************************************/

void printy()
{
    cout << endl
         << "Directory has been outputted to output.csv"
         << endl << endl;
}
