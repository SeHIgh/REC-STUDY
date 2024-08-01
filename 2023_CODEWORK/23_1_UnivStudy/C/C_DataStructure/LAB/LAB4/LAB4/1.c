//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX_SIZE 20
//
//typedef struct {
//	int row;
//	int col;
//	int value;
//}term;
//
//void Compress(int sparseMat[][MAX_SIZE], int row, int col, int cnt, term a[]);	//sparse matrix를 구조체로 변환하는 함수
//void fastTranspose(term a[], term b[]);
//
//int main(void) {
//	int ROW, COL, size, i, j, cnt = 0, temp = 1;
//	int arr[MAX_SIZE][MAX_SIZE] = { 0 };
//	term spa_mat1[MAX_SIZE * MAX_SIZE] = { 0 };
//	term spa_mat2[MAX_SIZE * MAX_SIZE] = { 0 };
//	FILE* fp1, * fp2;
//	fp1 = fopen("input.txt", "r");
//	fp2 = fopen("output.txt", "w");
//	//row,col 크기 입력
//	fscanf(fp1, "%d", &size);
//	ROW = size;
//	COL = size;
//	for (i = 1; i <= ROW; i++) {
//		for (j = 1; j <= COL; j++) {
//			fscanf(fp1, "%d", &arr[i][j]);
//			if (arr[i][j] != 0)
//				cnt++;
//		}
//	}
//	Compress(arr, ROW, COL, cnt, spa_mat1);
//	fastTranspose(spa_mat1, spa_mat2);
//	fprintf(fp2, "%d\n", spa_mat2[0].value);
//	for(i=1;i<=cnt;i++){
//		fprintf(fp2, "%d %d %d", spa_mat2[i].row, spa_mat2[i].col, spa_mat2[i].value);
//		if (i < cnt)
//			fprintf(fp2, "\n");
//	}
//	fclose(fp1);
//	fclose(fp2);
//	return 0;
//}
//
//
//void Compress(int sparseMat[][MAX_SIZE], int row, int col, int cnt, term a[]) {
//	int i, j, idx = 1;
//	a[0].row = row;
//	a[0].col = col;
//	a[0].value = cnt;
//	for (i = 1; i <= row; i++) {
//		for (j = 1; j <= col; j++) {
//			if (sparseMat[i][j] != 0) {
//				a[idx].row = i-1;
//				a[idx].col = j-1;
//				a[idx++].value = sparseMat[i][j];
//			}
//		}
//	}
//}
//
//void fastTranspose(term a[], term b[]) {
//	int rowTerms[MAX_SIZE] = { 0 }, startingPos[MAX_SIZE] = { 0 };
//	int i, j, numCols = a[0].col, numTerms = a[0].value;
//	b[0].row = numCols;
//	b[0].col = a[0].row;
//	b[0].value = numTerms;
//	if (numTerms > 0) {
//		for (i = 0; i < numCols; i++)
//			rowTerms[i] = 0;
//		for (i = 1; i <= numTerms; i++)
//			rowTerms[a[i].col]++;
//		startingPos[0] = 1;
//		for (i = 1; i < numCols; i++)
//			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
//		for (i = 1; i <= numTerms; i++) {
//			j = startingPos[a[i].col]++;
//			b[j].row = a[i].col;
//			b[j].col = a[i].row;
//			b[j].value = a[i].value;
//		}
//	}
//}