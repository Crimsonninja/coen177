#include <stdlib.h>
#include <stdio.h>

int search(int arr[], int lo, int hi, int n) {
	int index = -1;
	int i;
	for (i = lo;i < hi; ++i) {
		if (arr[i]==n) {
			index = i;
		}
	}
	return index;
}

int searchMinIndex(int arr[], int lo, int hi) {
	int minimum = arr[lo];
	int index = lo;
	int i;
	for (i = lo+1; i < hi; ++i) {
		if (arr[i]<minimum) {
			minimum = arr[i];
			index = i;
		}
	}
	return index;
}

int main(int argc, char* argv[]) {
	int pageSize = atoi(argv[1]);
	int pageRequests = 0;
	int pageFaults = 0;
	int numOfElts = 0;
	int puff[pageSize];
	int frequency[pageSize];
	int num;

	while(scanf("%d",&num)==1) {
		int indexIfFound = search(puff,0,numOfElts,num);
		if (indexIfFound==-1) {
			if (numOfElts < pageSize) {
				printf("Page replaced is: %d\n",puff[numOfElts]);
				puff[numOfElts] = num;
				frequency[numOfElts] = 1;
				++numOfElts;
			} else {
				int minIndex = searchMinIndex(frequency, 0, pageSize);
				printf("Page replaced is: %d\n",puff[minIndex]);
				puff[minIndex]=num;
				frequency[minIndex]=1;
			}
			++pageFaults;
		} else {
			++frequency[indexIfFound];
		}
		++pageRequests;
	}

	int i;
	printf("This is the array: \n");
	for (i = 0; i < pageSize; ++i) {
		printf("%d  %d\n", puff[i],frequency[i]);
	}
	printf("This is the number of page requests: %d\n", pageRequests);
	printf("This is the number of page faults: %d\n", pageFaults);
}
