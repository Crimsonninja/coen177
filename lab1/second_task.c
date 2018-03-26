#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 2

int main(int argc, char* argv[]) {
	// 8 nested if's that call fork if whatever fork returns is the child
	printf("I'm am the all father and my pid is %d\n", getpid());
	if (fork()==0) {
		printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
		if (fork()==0){
			printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
			if(fork()==0) {
				printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
				if (fork()==0) {
					printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
					if (fork()==0) {
						printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
						if (fork()==0) {
							printf("My pid is %d and my parent's pid is %d\n", getpid(),getppid());
							if (fork()==0) {
								printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
								if (fork()==0) {
									printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
								}
							}
						}
					}
				}
			}
		}
	}
}
