#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRUE 1
int main(){
        int pid,i=0;
        char tab[256],*s;

        while(TRUE){
                printf("prompt %d> ",i);
                fflush(stdout);
                s=gets(tab);
                if(s==NULL){
                        //CTRL+D pressed
                        fprintf(stderr,"Bye \n");
                        exit(0);
                }
                pid=fork();
                printf("Im running\n");
                switch(pid){
                        case 0:
                                printf("In the child\n");
                                execlp(tab,tab,NULL);
                                perror("EXEC");
                                exit(0);
                                break;
                        case -1:
                                perror("fork");
                                break;
                        default:
                                printf("in the parent.... w8 \n");
                                wait(0);
                                i++;
                }
        }
        return 0;
}

