/*File Name: readdirDriver.cpp

 Author: Shane Fleming
 Employer: Texas State University
 Date: 07/26/2019

 Read in from a directory and output first string of each file to .csv*/

#include "readdir.h"

using namespace std;
namespace fs = experimental::filesystem;

/******************************************************************
 main: creates variables, and calls functions, passes needed values
 calls dirLength and assigns to count
 passes count and dir to print, print cleans and exports
 ******************************************************************/

int main() 
{
    int count = 0, choice = 0, charRemove = 8, count_copy = 0;
    string dir, path;
    char dot;
    bool check = false; 

    while (check == false)
        {
           dir = dirInput();
           count = dirLength(dir);
           count_copy = count;
           char dirChar[count_copy+1];
           strcpy(dirChar, dir.c_str());

	   check = DirectoryExists(dirChar);
	}
        
    while (choice !=9)
        {
	   choice = menu();

           switch (choice)
               {    
    
                  case 1:
                      {
                         dot = '_';
                         print2(dir, count, dot);
                         printy();

                         break;
                      }
    
                  case 2:
                      {
                         dot = '-';
                         print2(dir, count, dot);
                         printy();

                         break;
                      }
    
                  case 3:
                      {
                         dot = '.';
                         print2(dir, count, dot);
                         printy();
     
                         break;
                      }
    
                  case 4:
                      {
                         dot = ',';
                         print2(dir, count, dot);
                         printy();
       
                         break;
                      }
    
                  case 5:
                      {
                         dot = ':';
                         print2(dir, count, dot);
                         printy();

                         break;
                      }
    
                  case 6:
                      {
                         dot = ' ';
                         print2(dir, count, dot);
                         printy();

                         break;
                      }

                  case 7:
                      {
                         cout << "Custom Stop Character? ";
                         cin >> dot;

                         print2(dir, count, dot);
                         printy();

                         break;
                      }

                  case 8:
                      {
                         cout << "Custom amount to save: ";
                         cin >> charRemove;

                         print(dir, count, charRemove);
                         printy();

                         break;
                      }
    
                  case 9:
                      {
                         cout << endl << "Thank you for using my Program!" 
                              << endl << endl;

                         return 0;
                      }

                  case 0:
                      {
                         cout << endl;
                         system("cat output.csv");
                         cout << endl;

                         break;
                      }

                  default:
                      {
                         cout << endl << "Please enter valid choice" 
                              << endl << endl;

                         break;
                      }
               } 
        }
    
     return 0;
}
