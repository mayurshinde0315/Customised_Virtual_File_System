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
// Stucture Name : Boot Block
// Discription : It Holds the  information to the Oprating System
//
/////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

/////////////////////////////////////////////////////////////
//
// Stucture Name : Super Block 
// Discription :  It Holds the Information of complete File System
//
/////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

/////////////////////////////////////////////////////////////
//
// Stucture Name : Inode
// Discription :  It Holds the Information of File 
//
/////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];    // file ch naav directory madhe ast
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount; 
    int Permission;
    char *Buffer;
    struct Inode *next;
};

typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

/////////////////////////////////////////////////////////////
//
// Stucture Name : FileTable
// Discription :  It Holds the Information of Opened Files 
//
/////////////////////////////////////////////////////////////

#pragma pack(1)
struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef struct FileTable FILETABLE;
typedef struct FileTable* PFILETABLE;

/////////////////////////////////////////////////////////////
//
// Stucture Name : UAREA
// Discription :  It Holds the Information of Process 
//
/////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

/////////////////////////////////////////////////////////////
//
//  Global varibles used in the Project
//
/////////////////////////////////////////////////////////////

struct BootBlock bootbobj;
struct SuperBlock superobj;
struct UAREA uareaobj; 

PINODE head = NULL;


/////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseUAREA
//  Description : It is Used to initilise UAREA
//  Author : Mayur Dattatray Shinde
//  Date :   31/08/2026
//
/////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    int i = 0;
    strcpy(uareaobj.ProcessName,"Myexe");

    for( i= 0; i< MAXOPENFILES; i++)
    {
        uareaobj.UFDT[i] =NULL;
    }

    printf("Marvellous CVFS : UAREA gets initialise Sucessfully \n");
}

/////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseSuperBlock
//  Description : It is Used to initilise UAREA
//  Author : Mayur Dattatray Shinde
//  Date :   31/08/2026
//
/////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXFILESIZE;

    printf("Marvellous CVFS : SuperBlock gets initialise Sucessfully \n");

}

/////////////////////////////////////////////////////////////
//
// Entry Point Function if CVFS Projects
//
/////////////////////////////////////////////////////////////

int main()
  
{
    InitialiseUAREA();
    InitialiseSuperBlock();
    
    
    return 0 ;
}