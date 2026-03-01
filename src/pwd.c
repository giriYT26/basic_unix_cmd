/*
 * unix-cmds-in-c
 *-------------------------------------------------------------------------------------------------------  
   A simple C program that mimics Unix user-utility commands.
   This particular program recreates `pwd` (Print Working Directory). 
 *-------------------------------------------------------------------------------------------------------
  Implementation:
     Uses getcwd(char *buf, size_t len) to fetch the current directory.
 *-------------------------------------------------------------------------------------------------------
  Platform Notes:
    Linux/Mac : getcwd() is in <unistd.h>
    Windows   : getcwd() is in <direct.h>
 *-------------------------------------------------------------------------------------------------------
  Reference:
    getcwd() source: https://github.com/gcc-mirror/gcc/blob/master/libiberty/getcwd.c
 *-------------------------------------------------------------------------------------------------------
  Author  : S GIRIDHARAN
  Compile :
    Windows : gcc pwd.c -o pwd.exe
    Linux   : gcc pwd.c -o pwd
 */

#include <stdio.h>
#ifdef _WIN32 // _win32 is def automatically by ur complier when ur using win 
    #include <direct.h>
#else
    #include <unistd.h>
#endif

void main(){
    // u can use a array or a pointer for the buff refer the src
    char buff[1024];
    getcwd(buff,sizeof(buff));
    printf("%s",buff);
}