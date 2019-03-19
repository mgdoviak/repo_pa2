#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ftw.h>
#include <dirent.h>
#include <string.h>
using namespace std;

int fileCount = 0;
int directoryCount = 0; 
int byteCount = 0;
  
int count(const char * filename, const struct stat * statptr, int flag) {
  switch(flag) {
    case FTW_F:
      fileCount++;
      byteCount += (intmax_t)statptr->st_size;
      break;
    case FTW_D:
      directoryCount++;
      break;
    case FTW_NS: 
      perror("This error occurred");
      break;
  }
  return 0;
}

int main(int argc, char * argv[]) {
  if (argc < 2) {
 	  cout << "No path provided" << endl;
		return 0;
  }
	if (argc > 2) {
		cout << "Invalid amount of arguments" << endl;
		return 0;
	}

  int ftw_flag;
  ftw_flag = ftw(argv[1], count, 1024);

	cout << "The total number of directories in directory " << argv[1] << " is: " <<  directoryCount << endl;
	cout << "The total number of files in directory " << argv[1] << " is: " <<  fileCount << endl;
	cout << "The total number of bytes occupied by all files in directory " << argv[1] << " is: " <<  byteCount << endl;
	
}