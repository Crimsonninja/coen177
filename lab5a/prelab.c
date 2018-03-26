#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hasher.h"
#define SIZE 1000

struct pair {
	char key[50];
	int value;
};

int searchmapdatastructure(struct pair arr[],int lo, int hi, char* text) {
	int index = -1;
	int i;
	for (i=lo; i < hi; ++i) {
		if(strcmp(arr[i].key,text)==0) {
			index = i;
		}
	}
	return index;
}

int main(int argc, char* argv[]) {
	Hasher *h = createHasher();
	struct pair mapdatastructure[1000];
	char buffer[50];
	int numOfElts = 0;
	while(scanf("%s",buffer)==1) {
		int indexIfFound = searchmapdatastructure(mapdatastructure,0,numOfElts,buffer);
		if (indexIfFound==-1) {
			if (numOfElts < 1000) {
				strcpy(mapdatastructure[numOfElts].key,buffer);
				mapdatastructure[numOfElts].value = h->hash(buffer);
				++numOfElts;
			} else {
				printf("Map Data Structure is full\n");
			}
		} else {
			printf("%d\n",mapdatastructure[indexIfFound].value);
		}
	}
}
