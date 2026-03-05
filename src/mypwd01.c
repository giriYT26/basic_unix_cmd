/*
 * unix-cmds-in-c
 *-------------------------------------------------------------------------------------------------------  
   A simple C program that mimics Unix user-utility commands.
   This particular program recreates `pwd` (Print Working Directory). 
 *-------------------------------------------------------------------------------------------------------
  Implementation:
     First i will see the System's Env if and print the path if it's not null.
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
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <direct.h>
    #define strcasecmp _stricmp
#else 
    #include <unistd.h>
#endif 

void help(){
    printf("pwd: Usage: pwd [options]:\n");
    printf("[options]:\n");
    printf("\t-l, -L\t,Prints the Local path (by default) same as echo $PWD\n");
    printf("\t-p, -P\t,Prints the Physical Path\n");
    printf("\t-h, -H, --help\t,Prints the help part\n\n");
    printf("NOTE: These are not Case-Insenstive");
}
void ppwd(){ 
    char buff[PATH_MAX];
    getcwd(buff,sizeof(buff));
    printf("%s",buff);

}
int main(int argc,char *argv[]){    
    if (argc > 1 && (strcasecmp(argv[1],"-h") == 0 || strcasecmp(argv[1],"--help") == 0)){
        help();
    }else if (argc > 1 && strcasecmp(argv[1],"-p") == 0){
        ppwd(); //print physical working dir        
    }else if ((argc > 1 && strcasecmp(argv[1],"-l") == 0) || (argc == 1)){
        char *pwd;
        pwd = getenv("PWD");
        if (pwd != NULL){
            printf("%s\n",pwd); 
        }else{
            ppwd();
        }
        
    }
    else{
        printf("pwd: Invalid option %s\n",argv[1]);
        printf("Try 'mypwd --help' for more information");
    }
    return 0;
    
        
}