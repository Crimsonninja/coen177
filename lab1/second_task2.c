#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 2

int main(int argc, char* argv[]) {
	printf("I am the all-father and my pid is %d\n",getpid());
	int i;
	int status;
	for (i = 0; i<2; i++) {
		if (fork()==0) {
			printf("My pid is %d and my parent's pid is %d\n", getpid(), getppid());
		
			if (fork()==0) {
				printf("My pid is %d and my parent's pid is %d\n", getpid(), getppid());
			}
			} else {
				waitpid(-1,&status,0);
			}
		} else {
			waitpid(-1,&status,0);
		}
	}
	return 0;
}
