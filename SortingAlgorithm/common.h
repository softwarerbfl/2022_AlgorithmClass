#pragma once
#include <stdio.h>
#include <stdlib.h> //rand()함수 
#include<time.h>
#include <stdbool.h>
#include <math.h>
typedef struct Q {
	int size;
	int *arr;
}Q;
void makeRand(int array[], int n, int seed); //1~n까지의 값을 random한 순서로 배열 생성
void printArray(int array[], int len);

void exchangeSort(int array[], int n);
void mergeSort(int array[], int n);
void merge(int u[], int h[], int n, int m, int S[]);

void swap(int* a, int* b);
int partition(int array[], int left, int right);
void quickSort(int array[], int len, int left, int right);

void siftdown(int array[], int i, int size);
void makeheap(int array[],int n);
void heapSort(int array[],int n);

void radixSort(int array[], int n);