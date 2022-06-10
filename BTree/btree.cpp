#include <iostream>
#include "common.h"
using namespace std;

int main() {
	int value;
	int n = 1000; //삽입할 원소의 개수
	BTree t(5);
	clock_t start, finish;
	double result=0.0;
	int* temp = (int*)malloc(sizeof(int) * n);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++) {
		value = rand() % 10000;
		for (int j = 0; j < i; j++) {
			if (value == temp[j]) {
				i--;
				break;
			}
		}

		start = clock();
		t.insert(value);
		finish = clock();
		
		result = result + (double)(finish - start)/CLOCKS_PER_SEC;
		temp[i] = value;
	}

	cout << "총 걸린 시간: " << result << "초\n";
	//cout << "Constructed tree : ";
	//t.traverse();
	return 0;
}
