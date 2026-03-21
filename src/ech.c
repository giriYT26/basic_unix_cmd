/*
    This a mini version of the linux user utilty cmd echo
*/

#include <stdio.h>

void help(){
    printf("ech: A mini version of echo\n");
    printf("\n");
    printf("Name\n\t ech - display a line of text\n");
    printf("SYNOPSIS\n\t ech[SHORT-OPTION]... [STRING]...\n\t ech LONG-OPTION\n");
    printf("DESCRIPTION\n\t ech the STRING to the stdout");
    printf("\n\t -n do not output the traling newline\n\t -e enables escape sequence");
    printf("\n\t -h --help display this help\n\t");

}

//void print()
int main(int argc,char *argv[]){
    int nflag = 1; // by default have trailing newlines
    int eflag = 0; // by default it doen't allow escape sequence
    argv++; //skips the program name 
    //argc--;
    
    while(*argv && **argv == '-'){
        if ((*(*argv+1) == 'n' || *(*argv+1) == 'N') && (*argv)[2] == '\0'){
            nflag = 0; 
        }
        else if ((*(*argv+1) == 'e' || *(*argv+1) == 'E') && (*argv)[2] == '\0'){
            eflag = 1;
        }
        else if ((*(*argv+1) == 'h' || *(*argv+1) == 'H') && (*argv)[2] == '\0'){
            help();
        }
        else break;
        //argc--;
        argv++;
    }
    //printf("%d\n",nflag) ;
    if (nflag == 1 && eflag == 0){
        while (*argv)
        {   
            if (eflag == 0){
                printf("%s",*argv);
            }
            argv++;
        }
        printf("\n");
    }else if ((nflag == 1 || nflag == 0 ) && eflag == 1){
        while (*argv){
            char *p = *argv;
            while (*p){
                if (*p == '\\'){
                    p++;
                    switch (*p)
                    {
                    case 'n':
                        printf("\n");
                        break;
                    case 't':
                        printf("\t");
                        break;
                    case '\\':
                        printf("\\");
                        break;
                    case 'r':
                        printf("\r");
                        break;
                    case 'c':
                        return 0;
                        break;
                    default:
                        printf("%c",*p);
                        break;
                    }
                }else printf("%c",*p);
                p++;
            }
            argv++;
            if (*argv){
                printf(" ");
            }
        }
    }
}