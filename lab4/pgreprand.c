#include <stdlib.h>
#include <stdio.h>

int search(int arr[], int lo, int hi, int n) {
	int index = -1;
	int i;
	for (i = lo; i < hi; ++i) {
		if (arr[i] == n) {
			index = i;
		}
	}
	return index;
}

int main(int argc, char* argv[]) {
	int pageSize = atoi(argv[1]);

	int puff[pageSize];

	int pageFaults = 0;
	int pageRequests = 0;
	int numOfElts = 0;

	int num;

	while(scanf("%d",&num)==1) {
		if (search(puff,0,numOfElts,num)==-1) {
			if (numOfElts<pageSize) {
				puff[numOfElts] = num;
				++numOfElts;
			} else {
				int randIndex = rand()%pageSize;
				printf("Page replaced is: %d\n",puff[randIndex]);
				puff[randIndex] = num;
			}
			++pageFaults;
		}
		++pageRequests;
	}

	// int i;
	// printf("This is the array:\n");
	// for (i = 0; i < pageSize; ++i) {
	// 	printf("%d\n",puff[i]);
	// }
	printf("This is the number of page requests: %d\n", pageRequests);
	printf("This is the number of page faults: %d\n", pageFaults);
}
