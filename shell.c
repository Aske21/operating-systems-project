#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>


#define MAXLET 1000 //max number of letters
#define MAXCOMM 100 //max number of commands

//clear shell using escape sequences
#define clear() printf("\033[H\033[J")


//shell banner
void shell_banner(){
clear();
printf("Operating Systems Lab Project \n");
printf("Shell made by: \n");
printf("Mahmut Besirevic \n");
printf("Asim Veledarevic \n");
printf("Mirza Kurtovic \n");

sleep(2);
clear();
}

//take input

int getInput(char* str){
//make buffer
char* tokens;
//set prompt and get input
tokens= readline("\no prompt$ ");
//add to history
if(strlen(tokens)!=0){
	//put input in history using readline history library
add_history(tokens);

strcpy(str,tokens);
return 0;
}else{
	return 1;
}
}


//print working directory
void printDir(){

char cwd[1024];
//get current working dir and print it
getcwd(cwd,sizeof(cwd));
printf("\nDir: %s",cwd);
}


//execute system commands
void execArgs(char** parsed){

//fork 
pid_t pid = fork();

//check for err
if (pid==-1){
	//Print err message
	printf("\nError, failed forking...\nResetting");
	return;

}else if(pid ==0){
	//if successfull fork but err executing
if(execvp(parsed[0],parsed)<0){
		printf("\nError, failed executing...\nResetting");
		}
		
exit(0);
}else{
//wait for chiled
wait(NULL);
return;
 }
}

//pipe handling

void execPiped(char** parsed, char** parsedpipe){
//0 for read end, 1 for write end
	int pipefd[2];
	// get pipe processes
	pid_t p1,p2;
	//if pipe err
	if(pipe(pipefd)<0){
		printf("\nError, pipe couldnt be initialized");
		return;
	}
	//fork first process
	p1=fork();
	if(p1<0){
		printf("\nError, couldnt fork");
		return;
	}
	if(p1==0){
		//child 1 execution
		//only needs to write at write end
		close(pipefd[0]);
		
		dup2(pipefd[1],STDOUT_FILENO);
		close(pipefd[1]);
		if(execvp(parsed[0],parsed)<0){
			printf("\nError executing first command... \nRestarting");
				exit(0);
		}
	}
		else{
			//parent execution
			p2=fork();
			if(p2<0){
				printf("\nError Forking");
				return;
			}
			//child 2 execution
			//only needs to read at read end
			if(p2==0){
				close(pipefd[1]);
				dup2(pipefd[0],STDIN_FILENO);
				close(pipefd[0]);
				if(execvp(parsedpipe[0],parsedpipe)<0){
					printf("\nError executing second command... \nRestarting");
					exit(0);
				}
				else{
					//parent execution, waiting for children
					wait(NULL);
					wait(NULL);
				}
			}
		

}
}

//built in help command
void openHelp(){
puts("\nSupported commands:"
	"\ncd"
	"\nls"
	"\nexit"
	"\nAll unix commands"
	"\nPiping"
	"\nSpace handling"
		
		);
return;
}

//built in command handling
int cmdHandler(char** parsed){
	int noOfCmds=3,i,switchArg=0;
	char* listOfCmds[noOfCmds];
	//basic command handler 
	listOfCmds[0]="exit";
	listOfCmds[1]="cd";
	listOfCmds[2]="help";
	
	for (i=0; i<noOfCmds; i++){
		if(strcmp(parsed[0],listOfCmds[i])==0){
			switchArg=i+1;
			break;
		}
	}
	switch (switchArg){
		case 1:
			printf("\nBye");
			exit(0);
		case 2:
			chdir(parsed[1]);
			return 1;
		case 3:
			openHelp();
			return 1;
		default:
			break;
	}
return 0;
}

//find pipe
int parsePipe(char* str, char** strpiped){

	int i;
	for(i=0;i<2;i++){
		//seperate on  | char
		strpiped[i]=strsep(&str,"|");
		if(strpiped[i]==NULL) break;
	}

	if(strpiped[1]==NULL) return 0; //return 0 if no pipe
       	else{return 1;}	
}

//parse commands
void parseSpace(char* str, char** parsed){
	int i;
	for (i=0;i<MAXCOMM; i++){
		//seperate string on space 
		parsed[i]=strsep(&str," ");
		if(parsed[i]==NULL) break;
		if (strlen(parsed[i])==0) i--;
	}
}

//process the input
int processString(char* str, char** parsed, char** parsedpipe){

char* strpiped[2];
int piped=0;

//get piped input(check if piped then parse)
piped=parsePipe(str,strpiped);
if(piped){
	//if piped check for spaces and parse them
	parseSpace(strpiped[0],parsed);
	parseSpace(strpiped[1],parsedpipe);
}else{
	//parse spaces on non piped input
	parseSpace(str,parsed);
}
// check if built in command and handle it
if(cmdHandler(parsed)) return 0;
else return 1 + piped;

}



int main(){
	//initialize strpngs 
        char inputString[MAXLET],*parsedArgs[MAXCOMM];
	char* parsedArgsPiped[MAXCOMM];
	int execFlag=0;
	//display shell banner
	shell_banner();
	while(1){
		//print current dir
		printDir();
		//get input
		if(getInput(inputString)) continue;
		//process input
		execFlag=processString(inputString,parsedArgs,parsedArgsPiped);
		//returns 0 if no comkmand, or built in command
		//1 for simple command, 2 for a pipe

		//if simple pipe
		if(execFlag==1) execArgs(parsedArgs);
		//if piped
		if(execFlag==2) execPiped(parsedArgs,parsedArgsPiped);
	}
	return 0;
}

