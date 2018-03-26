#include <stdlib.h>
#include <stdio.h>
#define MAX_BUFFER_LENGTH 1024	// Reading 1 MB at a time

int main(int argc, char* argv[]){
	FILE *fp = fopen(argv[1],"r");	//  take in the file as an argument
	char *puff;
	puff = (char *)malloc(sizeof(char)*MAX_BUFFER_LENGTH);
	unsigned long long fileSize = (unsigned long long) atoi(argv[2])*1073741824;	// take in the number of gigabytes as second argument
	unsigned long long counter = 0;
	while (fread(puff,MAX_BUFFER_LENGTH,1,fp)==1) {}	// fread simply moves the pointer so just loop and keep reading until end of file
	return 0;
}
