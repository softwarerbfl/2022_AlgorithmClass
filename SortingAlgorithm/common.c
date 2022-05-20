#include "common.h"
#include <stdio.h>
#include <stdlib.h> //rand()함수 
#include<time.h>
//seed와 배열의 길이, 배열을 인자로 받아와 배열의 값을 랜덤으로 중복없이 넣어주는 함수 
void makeRand(int array[], int n, int seed) {
	int flag = 0;
	srand(seed);
	array[0] = rand() % n + 1;
	for (int i = 1; i < n; i++) {
		int random = rand() % n + 1;
		for (int j = 0; j < i; j++) {
			if (array[j] == random) {
				i--;
				flag = 1;
			}
		}
		if (flag == 1) {
			flag = 0;
			continue;
		}
		else {
			array[i] = random;
		}
	}
}
void printArray(int array[], int len) {
	for (int i = 0; i < len/10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d   ", array[i * 10 + j]);
		}
		printf("\n");
	}
}

//exchangeSort 구현
void exchangeSort(int array[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[j] < array[i]) {
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}
//mergeSort 구현
void mergeSort(int array[], int n) {
	if (n > 1) {
		int mid = n / 2;
		int* U = (int*)malloc(sizeof(int) * mid);//mid값을 기준으로 왼쪽 배열
		int* H = (int*)malloc(sizeof(int) * (n - mid)); //mid값을 기준으로 오른쪽 배열
		for (int i = 0; i < mid; i++) {
			U[i] = array[i];
		}
		for (int i = 0; i < n-mid; i++) {
			H[i] = array[i + mid];
		}
		mergeSort(U, mid); //왼쪽 배열 정렬하는 재귀
		mergeSort(H, n - mid); //오른쪽 배열 정렬하는 재귀
		merge(U, H, mid, n - mid, array); //정렬된 두 배열을 병합
	}
}
//mergeSort구현에 필요한 합병 함수 구현
void merge(int u[], int h[], int n, int m, int array[]) {
	int ucount = 0;
	int hcount = 0;
	int index = 0;

	while (ucount<n && hcount<m) {
		//왼쪽 배열과 오른쪽 배열을 비교하면서 작은 값을 순서대로 array에 담아준다. 
		if (u[ucount] > h[hcount]) {
			array[index] = h[hcount];
			hcount++;
		}
		else {
			array[index]=u[ucount];
			ucount++;
		}
		index++;
	}
	//한 쪽의 배열이 비었을 경우 나머지 배열에 남은 값을 모두 array의 뒷 쪽에 담는다.
	if (ucount < hcount) {
		for (int i = ucount; i < n; i++) {
			array[index] = u[i];
			index++;
		}
	}
	else {
		for (int j = hcount; j < m; j++) {
			array[index] = h[j];
			index++;
		}
	}
}
//두 변수의 값 교환
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//맨 앞에 와있는 pivot값을 기준으로 앞 뒤로 나누고 pivot값 원위치 
int partition(int array[], int left, int right) {
	int pivot = array[left]; //quickSort로부터 pivot값을 맨 앞에 받아옴 
	int low = left + 1; //맨 앞은 피봇이므로 제외
	int high = right; //맨 뒷 값 지정
	while (high >= low) {
		while ((pivot >= array[low]) && (low <= right)) low++;
		while ((pivot <= array[high]) && high >= (left + 1))high--;
		//서로 지나치지 않았으면 swap
		if (low <= high) {
			swap(&array[low], &array[high]);
		}
	}
	//pivot과 high위치 값 swap
	swap(&array[high], &array[left]);
	return high; //pivot위치 return 
}
//quickSort구현
void quickSort(int array[], int len, int left, int right) {
	if (left <= right) {
		int random = rand() % len+left;
		swap(&array[left], &array[random]);

		int pivot = partition(array, left, right);

		quickSort(array, pivot - left, left, pivot - 1);
		quickSort(array, right - pivot, pivot + 1, right);
	}
	
}

//heap의 i번째 인덱스를 제 위치로 바꿔주는 함수 
void siftdown(int array[], int i, int size) {
	int maxIndex = i;
	int left = 2 * i + 1;
	int right =2 * i + 2;
	if (left < size && array[left] > array[maxIndex]) {
		maxIndex = left;
	}
	if (right < size && array[right] > array[maxIndex]) {
		maxIndex = right;
	}
	if (maxIndex != i) {
		swap(&array[maxIndex], &array[i]);
		siftdown(array, maxIndex, size);
	}
}
//heap구조로 만들어 주기위해 반복문으로 siftdown함수를 호출하는 역할 
void makeheap(int array[], int n) {
	int i;
	for (int i = n/2 -1; i >= 0; i--) {
		siftdown(array, i, n);
	}
}
//heapSort구현 
void heapSort(int array[], int n) {
	int i;
	makeheap(array, n);
	for (i = n - 1; i > 0; i--) {
		swap(&array[0], &array[i]); //맨 마지막 값을 가져옴
		siftdown(array, 0,i); //크기가 i인 힙의 root값위치 조정
	}
}



void radix(int array[], int n, int  digit) {
	int index;
	int val1 = (int)pow(10, digit);
	int val2 = (int)pow(10, digit - 1);
	int* temp = (int*)malloc(sizeof(int) * n);
	int count = 0;
	//자리수에 맞춰 각각 큐에 넣어주기
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < n; j++) {
			index = (array[j] % val1) / val2; //digit자리수 
			if (index == i) {
				temp[count]=array[j];
				count++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		array[i] = temp[i];
	}
	
}
//radix정렬 수행 
void radixSort(int array[], int n) {
	int count = 1,tmp;
	tmp = n;
	while (1) {
		tmp = tmp / 10;
		if (tmp == 0)break;
		else count++;
	 } //count는 최대 자리수 
	for (int i = 1; i <= count; i++) {
		radix(array, n, i); //i번째 자리수 기준으로 정렬 
	}
}
