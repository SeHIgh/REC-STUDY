#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 20

typedef struct {
	int row;
	int col;
	int value;
}term;

void make_arr(term Mat[], int row, int col, int cnt, int a[][MAX_SIZE]);
void Compress(int sparseMat[][MAX_SIZE], int row, int col, int cnt, term a[]);
void mat_multiply(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int mat3[][MAX_SIZE], int row1, int col1, int col2);

int main(void) {
	int i, cnt = 0;

	term spa_mat1[MAX_SIZE * MAX_SIZE] = { 0 };
	term spa_mat2[MAX_SIZE * MAX_SIZE] = { 0 };
	term spa_mat3[MAX_SIZE * MAX_SIZE] = { 0 };

	int arr1[MAX_SIZE][MAX_SIZE] = { 0 };
	int arr2[MAX_SIZE][MAX_SIZE] = { 0 };
	int result[MAX_SIZE][MAX_SIZE] = { 0 };

	FILE* fp1, * fp2, * fp3;
	fp1 = fopen("input1.txt", "r");
	fp2 = fopen("input2.txt", "r");
	fp3 = fopen("output.txt", "w");
	fscanf(fp1, "%d %d %d", &spa_mat1[0].row, &spa_mat1[0].col, &spa_mat1[0].value);
	for (i = 1; i <= spa_mat1[0].value; i++)
		fscanf(fp1, "%d %d %d", &spa_mat1[i].row, &spa_mat1[i].col, &spa_mat1[i].value);

	fscanf(fp2, "%d %d %d", &spa_mat2[0].row, &spa_mat2[0].col, &spa_mat2[0].value);
	for (i = 1; i <= spa_mat2[0].value; i++)
		fscanf(fp2, "%d %d %d", &spa_mat2[i].row, &spa_mat2[i].col, &spa_mat2[i].value);
	
	//구조체를 배열로 바꿔주는 과정
	make_arr(spa_mat1, spa_mat1[0].row, spa_mat1[0].col, spa_mat1[0].value, arr1);
	make_arr(spa_mat2, spa_mat2[0].row, spa_mat2[0].col, spa_mat2[0].value, arr2);
	
	//바뀐 배열들을 가지고 행렬의 곱셈을 시행
	mat_multiply(arr1, arr2, result, spa_mat1[0].row, spa_mat2[0].col, spa_mat1[0].col);
	
	//최종 결과 행렬의 0이 아닌값의 개수 구하기
	for (int i = 0; i < spa_mat1[0].row; i++)
		for (int j = 0; j < spa_mat2[0].col; j++)
			if (result[i][j] != 0)
				cnt++;

	//곱셈의 결과 배열을 다시 희소행렬로 변환
	Compress(result, spa_mat1[0].row, spa_mat2[0].col, cnt, spa_mat3);

	//희소행렬로 변환된 값을 출력
	fprintf(fp3, "%d\n", spa_mat3[0].value);
	for (i = 1; i <= spa_mat3[0].value; i++) {
		fprintf(fp3, "%d %d %d", spa_mat3[i].row, spa_mat3[i].col, spa_mat3[i].value);
		if (i < spa_mat3[0].value)
			fprintf(fp3, "\n");
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}

void make_arr(term Mat[], int row, int col, int cnt, int a[][MAX_SIZE]) {
	int i;
	for (i = 1; i <= cnt; i++) {
		a[Mat[i].row][Mat[i].col] = Mat[i].value;
	}
}
void Compress(int sparseMat[][MAX_SIZE], int row, int col, int cnt, term a[]) {
	int i, j, idx = 1;
	a[0].row = row;
	a[0].col = col;
	a[0].value = cnt;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (sparseMat[i][j] != 0) {
				a[idx].row = i;
				a[idx].col = j;
				a[idx++].value = sparseMat[i][j];
			}
		}
	}
}
void mat_multiply(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int mat3[][MAX_SIZE], int row1, int col1, int col2) {
	int i, j, k;
	for (i = 0; i < row1; i++)
		for (j = 0; j < col2; j++)
			for (k = 0; k < col1; k++)
				mat3[i][j] += mat1[i][k] * mat2[k][j];
}