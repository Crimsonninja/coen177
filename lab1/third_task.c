#include <stdlib.h>
#include <stdio.h>
/*
 * The basic idea is that we will go down by levels. We will create the left child, and then go down one level
 * creating two children at a time.
 */ 
int main(int argc, char* argv[]) {
        int counter;
        int status;
        counter = 12;	// counter to keep track of number of children created
        printf("I am the allfather and my pid is %d\n", getpid());
        while (counter > 0) {
                if (fork() == 0) {	//creates the second child in the level that does nothing (has no child itself)
                        printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
                        break;
                } else {
                        waitpid(-1,&status,0);
                }
                if (fork()!=0) {	//creates the first child in the level
                        printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
			waitpid(-1,&status,0);
                        break;
                }
		if (counter==2) {	// this is a case that will add a child at the bottom bringing the total number of children to 12
			if (fork()==0) {
				waitpid(-1,&status,0);
				break;
			} else {
				printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
			}
		}
                counter = counter - 2;	// each time, we decrement the counter by 2
        }       
}
