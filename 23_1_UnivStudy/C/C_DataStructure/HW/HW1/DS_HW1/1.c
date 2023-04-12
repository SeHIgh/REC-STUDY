//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX_SIZE 20
//typedef struct testlist {
//	int num;
//	char name[MAX_SIZE];
//	float score1;
//	float score2;
//	float sum;
//}testlist;
//
//int main(void) {
//	int i;
//	FILE* fp1, * fp2;
//	testlist test1[MAX_SIZE] = { 0 };			//점수 합산을 0으로 초기화 시켜두기위해
//	fp1 = fopen("input.txt", "r");
//	fp2 = fopen("output.txt", "w");
//	i = 0;
//	while (fscanf(fp1, "%d %s %f %f", &test1[i].num, &test1[i].name, &test1[i].score1, &test1[i].score2) != EOF){
//		test1[i].sum = test1[i].score1 + test1[i].score2;
//		i++;
//	}
//	for (int j = 0; j < i; j++) {				// i에 기록된 test1의 인원수만큼 반복
//		fprintf(fp2, "%d %s %.1f %.1f %.1f", test1[j].num, test1[j].name, test1[j].score1, test1[j].score2, test1[j].sum);
//		if (j != i - 1)							// 마지막 행의 기록 시 엔터 미입력을 위해
//			fprintf(fp2, "\n");
//	}
//	fclose(fp1);
//	fclose(fp2);
//	return 0;
//}