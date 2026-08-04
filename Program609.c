/////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
/////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>

/////////////////////////////////////////////////////////////
//
// User Defined Macros
//
/////////////////////////////////////////////////////////////


#define MAXINODE 10
#define MAXFILESIZE 50
#define MAXOPENFILES 10

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

#define REGULARFILE 1
#define SPECIALFILE 2

/////////////////////////////////////////////////////////////
//
// User Define Macros For Error Handling
//
/////////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER -1

#define ERR_NO_INODES -2

#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4

#define Err_PERMISSION_DENIED -5

#define ERR_INSUFFICENT_SPACE -6
#define ERR_INSUFFICENT_DATA -7

#define ERR_MAX_FILES_OPEN -8


/////////////////////////////////////////////////////////////
//
// Entry Point Function if CVFS Projects
//
/////////////////////////////////////////////////////////////


int main()
  
{
    

    
    return 0 ;
}