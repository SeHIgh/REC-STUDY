#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

void make_randnum(int* arr, int size);

int main(void) {
	int i, j, k = 0, rand_arr[MAX_SIZE] = { 0 }, Quotient[5][1] = { 0 };
	int** arr, sum;

	make_randnum(rand_arr, MAX_SIZE);

	for (i = 0; i < MAX_SIZE; i++)
		Quotient[rand_arr[i] / 5][0]++; 

	arr = (int**)malloc(sizeof(int*) * 5);
	for (i = 0; i < 5; i++) {
		if (Quotient[i][0] > 0)
			arr[i] = (int*)malloc(Quotient[i][0] * sizeof(int));
		else
			arr[i] = (int*)malloc(1 * sizeof(int));
	}


	while (k < MAX_SIZE) {
		for (i = 0; i < 5; i++) {
			for (j = 0; j < Quotient[i][0]; j++) {
				if ((arr[i][j] < 0) || (arr[i][j] > 24))
					if ((rand_arr[k] / 5) == i) {
						arr[i][j] = rand_arr[k++];
						break;
					}
			}
			if (Quotient[i][0] == 0)
				arr[i][0] = -1;
		}
	}

	for (i = 0; i < 5; i++) {
		sum = 0;
		printf("arr[%d] = ", i);
		if (Quotient[i][0] > 0) {
			for (j = 0; j < Quotient[i][0]; j++) {
				sum += arr[i][j];
				printf("%d ", arr[i][j]);
				if (j < Quotient[i][0] - 1)
					printf("+ ");
				else
					printf("= %d", sum);
			}
		}
		else {
			sum += arr[i][0];
			printf("%d ", arr[i][0]);
			printf("= %d", sum);
		}
		if (i < 4)
			printf("\n");
	}

	free(arr);
	return 0;
}

void make_randnum(int* arr, int size) {		//중복없이 난수 생성
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < size; i++) {
		arr[i] = rand() % 25;
		for (j = 0; j < i; j++) {
			if (arr[i] == arr[j]) i--;
		}
	}
}