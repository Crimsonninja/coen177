#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_COMMAND_LENGTH 30

int main(int argc, char* argv[]) {
	int status;
	char singleCommand[MAX_COMMAND_LENGTH+1];		//initialize character array to store the command
	while (TRUE) {
		printf("Type in a command: ");
		
		scanf("%s",singleCommand);
		if (strcmp(singleCommand,"exit")==0) {		//compare if the input command is "exit"
			exit(0);				//if so, exit
		}
		else if (fork()!=0) {				//if this is parent
			waitpid(-1,&status,0);			//wait for child to finish
		} else {
			char *argv[3];				//initialize character array and put the input in first position
			argv[0]=singleCommand;
			argv[1]=NULL;
			argv[2]=NULL;
			execvp(singleCommand, argv);		//execvp the command
			exit(0);
		}
	}
}
