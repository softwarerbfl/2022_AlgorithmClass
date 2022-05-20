#include "common.h"
int main() {
	clock_t start, end;
	float proc[5][5];
	int dataNum[5] = { 100,500,1000,5000,10000 };
	int array[10000];

	//exchangeSort실행
	printf("########exchangeSort########\n");
	for (int a = 0; a < 5; a++) {
		int* array = (int*)malloc(sizeof(int) * dataNum[a]);
		makeRand(array, dataNum[a], 1);
		start = clock();
		exchangeSort(array, dataNum[a]);
		end = clock();
		proc[0][a] = (float)(end - start) / CLOCKS_PER_SEC;
		printf("%d개의 데이터 소요시간: %.9f\n", dataNum[a],proc[0][a]);
		
		free(array);
	}
	//mergeSort실행
	printf("########mergeSort########\n");
	for (int a = 0; a < 5; a++) {
		int* array = (int*)malloc(sizeof(int) * dataNum[a]);
		makeRand(array, dataNum[a], 1);
		start = clock();
		mergeSort(array, dataNum[a]);
		end = clock();
		proc[1][a] = (float)(end - start) / CLOCKS_PER_SEC;
		printf("%d개의 데이터 소요시간: %.9f\n", dataNum[a], proc[1][a]);
		free(array);
	}
	//quickSort실행
	printf("########quickSort########\n");
	for (int a = 0; a < 5; a++) {
		int* array = (int*)malloc(sizeof(int) * dataNum[a]);
		makeRand(array, dataNum[a], 1);
		start = clock();
		quickSort(array, dataNum[a],0,dataNum[a]-1);
		end = clock();
		proc[2][a] = (float)(end - start) / CLOCKS_PER_SEC;
		printf("%d개의 데이터 소요시간: %.9f\n", dataNum[a], proc[2][a]);
		free(array);
	}
	
	//heapSort실행
	printf("########heapSort########\n");
	for (int a = 0; a < 5; a++) {
		int* array = (int*)malloc(sizeof(int) * dataNum[a]);
		makeRand(array, dataNum[a], 1);
		start = clock();
		heapSort(array,dataNum[a]);
		end = clock();
		proc[3][a] = (float)(end - start) / CLOCKS_PER_SEC;
		printf("%d개의 데이터 소요시간: %.9f\n", dataNum[a], proc[3][a]);
		free(array);
	}
	
	//radixSort실행
	printf("########radixSort########\n");
	for (int a = 0; a < 5; a++) {
		int* array = (int*)malloc(sizeof(int) * dataNum[a]);
		makeRand(array, dataNum[a], 1);
		start = clock();
		radixSort(array, dataNum[a]);
		end = clock();
		proc[4][a] = (float)(end - start) / CLOCKS_PER_SEC;
		printArray(array, dataNum[a]);
		printf("%d개의 데이터 소요시간: %.9f\n", dataNum[a], proc[4][a]);
		free(array);
	}
	return 0;
}




