#include <stdio.h>
#include <stdlib.h>
#include "Hasher.h"

unsigned char* concaten(unsigned char* hashValue, char* buffer, unsigned char* dest) {
	if (hashValue[0]!=0) {
		dest = malloc(64+strlen(buffer));
		memcpy(dest,hashValue,64);
		strcpy(dest+64, buffer);
	} else {
		dest = malloc(strlen(buffer)+1);
		strcpy(dest, buffer);
	}
	return dest;
}

int main(int argc, char* argv[]) {
	if (argc!=2) {
		printf("Wrong # of arguments");
		return 0;
	}
	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL) {
		printf("File does not exist\n");
		return 0;
	}

	Hasher *h = createHasher();
	int hashLen;
	unsigned char *hashValue;
	char buffer[100];
	unsigned char buffer2[129];
	unsigned char buffer3[129];
	unsigned char* foo;
	unsigned char newArr[64];
	newArr[0]='\0';
	int stringLength;
	int i;
	int c;
	while(!feof(fp)) {
		for (i = 0; i < 3; ++i) {
			c = fgetc(fp);
			buffer[i] = c;
		}
		stringLength = atoi(buffer);
		for (i=0; i < stringLength; ++i) {
			c = fgetc(fp);
			buffer[i] = c;
		}
		buffer[i]='\0';
		if (buffer[0]=='\0') {
			printf("Got to this if\n");
			for (i=0;i<64;++i) {
				sprintf(&buffer3[i*2],"%02x",newArr[i]);
			}
			for (i=0; i < 128; ++i) {
				if(buffer2[i]!=buffer3[i]) {
					printf("buffer2: %s\n", buffer2);
					printf("buffer3: %s\n", buffer3);
					printf("Omission detected!\n");
					return 0;
				}
			}
		}

		fseek(fp,128,SEEK_CUR);
		for (i = 0; i < 128; ++i) {
			c = fgetc(fp);
			buffer2[i] = c;
		}

		foo = concaten(newArr,buffer,foo);
		hashLen = h->hash(foo,&hashValue);
		memcpy(newArr,hashValue,64);
	}
}
