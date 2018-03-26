#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hasher.h"

unsigned char* concaten(unsigned char* hashValue, char* buffer, unsigned char* dest) {
	//printf("%d",sizeof(hashValue));
	if (hashValue[0]!='\0') {
		dest=malloc(sizeof(hashValue)+strlen(buffer));
		memcpy(dest,hashValue,sizeof(hashValue));
		strcpy(dest+64,buffer);
	} else {
		dest = malloc(strlen(buffer)+1);
		strcpy(dest,buffer);
		
	}
	return dest;
}

int main(int argc, char* argv[]) {
	Hasher *h = createHasher();
	int hashLen;
	char buffer[500];
	char hashKey[65];
	unsigned char *prevhashVal=calloc(64,sizeof(unsigned char));
	unsigned char *hashValue;
	while(scanf("%s",buffer)==1) {
		printf("%03d",strlen(buffer));
		printf("%s", buffer);
		hashLen = h->hash(buffer,&hashValue);
		printHash(hashValue,hashLen);
		unsigned char* foo;
		foo = concaten(prevhashVal, buffer,foo);
		hashLen = h->hash(foo,&hashValue);
		printHash(hashValue,hashLen);
		// copy hashValue into prevhashVal
		memcpy(prevhashVal,hashValue,sizeof(hashValue));
	}
}
