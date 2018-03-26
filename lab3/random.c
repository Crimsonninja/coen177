#include <stdlib.h>
#include <stdio.h>
#define MAX_BUFFER_LENGTH 1024	// Reading 1 MB at a time

int main(int argc, char* argv[]) {
	FILE *fp = fopen(argv[1], "r");		//  take in the file as an argument
	char *puff;
	puff = (char *)malloc(sizeof(char)*MAX_BUFFER_LENGTH);
	unsigned long long fileSize = (unsigned long long) atoi(argv[2])*1073741824;	// take in the number of gigabytes as second argument
	unsigned long long counter = 0;		// this counter variable keeps track of the number of bytes we have read
	while (counter < fileSize) {
		unsigned long long randomOffset=rand()%(fileSize-MAX_BUFFER_LENGTH);
		fseek(fp,randomOffset,0);
		fread(puff,MAX_BUFFER_LENGTH,1,fp);
		counter+=MAX_BUFFER_LENGTH;
	}
}
