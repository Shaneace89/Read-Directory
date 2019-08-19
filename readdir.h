/*File Name: readdir.h

  Author: Shane Fleming
  Employer: Texas State University
  Date: 07/26/2019

  Read in from a directory and output first string of each file to .csv*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <experimental/filesystem>
#include <dirent.h>
#include <bits/stdc++.h>

using namespace std;
namespace fs = experimental::filesystem;

bool DirectoryExists(const char*);
int menu();
string dirInput();
int dirLength(string);
void print(string, int, int);
void print2(string, int, char);
void printy();
