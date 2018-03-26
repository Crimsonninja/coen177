#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char* argv[]) {
        int counter;
        int status;
        counter = 16;
        printf("I am the allfather and my pid is %d\n", getpid());
	
	while (counter > 0) {
                if (fork() == 0) {
                        printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
                        break;
                } else {
                        waitpid(-1,&status,0);
			if (counter==16) {
				if (fork()==0) {
					printf("My ppid %d and my parent's pid is %d\n", getpid(), getppid());
					exit(0);
				} else {
					waitpid(-1,&status,0);
				}
			}
                }
                if (fork()!=0) {
                        //waitpid(-1,&status,0);
                        printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
                        waitpid(-1,&status,0);
                        break;
                }
                if (counter==2) {
                        if (fork()==0) {
                                //printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
                                waitpid(-1,&status,0);
                                break;
                        } else {
                                //break;
                                printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
                                //waitpid(-1,&status,0);
                        }
                }
                counter = counter - 2;
        }
}

