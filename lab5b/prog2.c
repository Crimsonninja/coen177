#include <stdio.h>
#include <stdlib.h>
#include "Hasher.h"


int main(int argc, char* argv[]) {
	if (argc!=2) {
		printf("Wrong # of arguments");
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File does not exist\n");
		return 0;
	}
	Hasher *h = createHasher();
	char buffer[100];
	unsigned char buffer2[129];
	int hashLen;
	unsigned char *hashValue;
	int stringLength;
	int i;
	int c;
	while(!feof(fp)) {
		for (i = 0; i < 3; ++i) {
			c = fgetc(fp);
			buffer[i] = c;
		}
		stringLength = atoi(buffer);
		for (i = 0; i < stringLength; ++i) {
			c = fgetc(fp);
			buffer[i] = c;
		}
		buffer[i]='\0';
		if (buffer[0]=='\0'){}
			printf("Success!\n");
			return 0;
		}

		hashLen = h->hash(buffer,&hashValue);
		for(i = 0; i < 64; ++i) {
			sprintf(&buffer2[i*2], "%02x", hashValue[i]);
		}
		for (i = 0; i < 128; ++i) {
			c = fgetc(fp);
			if (c!=buffer2[i]) {
				printf("This string failed: %s\n",buffer);
				return 0;
			}
		}
		fseek(fp,128,SEEK_CUR);
	}

}
