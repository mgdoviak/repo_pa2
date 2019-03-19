#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ftw.h>
#include <dirent.h>
#include <string.h>
#define MAX_BUF 1024 
using namespace std; 


int main(int argc, char * argv[]) {
  if (argc < 2) {
 	  cout << "No option provided" << endl;
		return 0;
  }
  if (argc > 2) {
    cout << "Not the right amount of arguments" << endl;
    return 0;
  }
  
  string lineNumber[3];
  string tempString;
  
  getline(cin, tempString);
  lineNumber[0] = tempString;
  getline(cin, tempString);
  lineNumber[1] = tempString;
  getline(cin, tempString);
  lineNumber[2] = tempString;
 
  if(strcmp(argv[1], "-d") == 0) 
    cout << lineNumber[0] << endl;
  else if(strcmp(argv[1], "-f") == 0) 
    cout << lineNumber[1] << endl;
  else if(strcmp(argv[1], "-b") == 0) 
    cout << lineNumber[2] << endl;
  else
    cout << "Not a valid option" << endl;
 
  return 0;
}