#include <stdlib.h>
#include <stdio.h>

int search(int arr[], int lo, int hi, int n) {
	int index = -1;
	int i;
	for (i = lo; i < hi; ++i) {
		if (arr[i]==n) {
			index = i;
		}
	}
	return index;
}

int searchMinIndex(int arr[], int lo, int hi) {
	int minimum=arr[lo];
	int index = lo;
	int i;
	for (i=lo+1; i < hi; i++) {
		if (arr[i]<minimum) {
			index=i;
			minimum = arr[i];
		}
	}
	return index;
}

int main(int argc, char *argv[]) {
	int pageSize = atoi(argv[1]);
	int pageRequests = 0;
	int pageFaults = 0;
	int globalCounter = 0;
	int numOfElts = 0;

	int num;
	int puff[pageSize];
	int position[pageSize];

	while(scanf("%d",&num)==1) {
		int indexIfFound = search(puff,0,numOfElts,num);
		if (indexIfFound==-1) {
			if (numOfElts < pageSize) {
				printf("Page replaced is: %d\n",puff[numOfElts]);
				puff[numOfElts]= num;
				position[numOfElts] = globalCounter;
				++numOfElts;
			} else {
				int minIndex = searchMinIndex(position,0,pageSize);
				printf("Page replaced is: %d\n",puff[minIndex]);
				puff[minIndex]=num;
				position[minIndex]=globalCounter;
			}
			++pageFaults;
		} else {
			position[indexIfFound] = globalCounter;
		}
		++pageRequests;
		++globalCounter;
	}

	int i;
	//printf("This is the array:\n");
	//for (i=0;i < pageSize;++i){
	//	printf("%d %d\n",puff[i],position[i]);
	//}
	printf("The number of page requests is %d\n", pageRequests);
	printf("The number of page faults is %d\n", pageFaults);
}
