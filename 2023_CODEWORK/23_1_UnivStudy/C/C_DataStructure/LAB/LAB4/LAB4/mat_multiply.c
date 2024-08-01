//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX_SIZE 20
//
//void mat_multiply(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int mat3[][MAX_SIZE], int row1, int col1, int col2);
//
//int main(void)
//{
//    FILE* fp1, * fp2, *fp3;
//    fp1 = fopen("input.txt", "r");
//    fp2 = fopen("input1.txt", "r");
//    fp3 = fopen("output2.txt", "w");
//
//    int num;
//
//    int mat1[MAX_SIZE][MAX_SIZE] = { 0 };
//    int mat2[MAX_SIZE][MAX_SIZE] = { 0 };
//    int result[MAX_SIZE][MAX_SIZE] = { 0 };
//
//    fscanf(fp1, "%d", &num);
//    fscanf(fp2, "%d", &num);
//    for (int i = 0; i < num; i++) {
//        for (int j = 0; j < num; j++) {
//            fscanf(fp1, "%d", &mat1[i][j]);
//        }
//    } 
//    for (int i = 0; i < num; i++) {
//        for (int j = 0; j < num; j++) {
//            fscanf(fp2, "%d", &mat2[i][j]);
//        }
//    }
//    mat_multiply(mat1, mat2, result, num, num, num);
//
//    for (int i = 0; i < num; i++)
//    {
//        for (int j = 0; j < num; j++)
//        {
//            fprintf(fp3,"%5d ", result[i][j]);
//        }
//        fprintf(fp3, "\n");
//    }
//    fclose(fp1);
//    fclose(fp2);
//    fclose(fp3);
//    return 0;
//}
//
//void mat_multiply(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int mat3[][MAX_SIZE], int row1, int col1, int col2) {
//    int i, j, k;
//    for (i = 0; i < row1; i++)
//        for (j = 0; j < col2; j++)
//            for (k = 0; k < col1; k++)
//                mat3[i][j] += mat1[i][k] * mat2[k][j];
//}