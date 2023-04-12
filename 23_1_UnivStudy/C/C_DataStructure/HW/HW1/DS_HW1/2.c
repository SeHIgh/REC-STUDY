//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
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
//	int cnt = 1, i;
//	FILE* fp1, * fp2;
//	testlist* test1 = (testlist*)calloc(cnt, sizeof(testlist));		//점수 합산을 0으로 초기화 시켜두기위해
//	testlist* buff;													//임시 구조체 버퍼 지정
//	fp1 = fopen("input.txt", "r");
//	fp2 = fopen("output.txt", "w");
//	i = 0;
//	while (fscanf(fp1, "%d %s %f %f", &test1[i].num, &test1[i].name, &test1[i].score1, &test1[i].score2) != EOF) {
//		test1[i].sum = test1[i].score1 + test1[i].score2;
//		i++;
//		buff = realloc(test1, sizeof(testlist) * (++cnt));			//메모리 재할당 시 기존 메모리의 미해제 및 재할당 실패 시를 대비 임시 구조체에 주소 저장 
//		if (buff != NULL) {
//			test1 = buff;											//NULL값이 아닐 때 데이터 처리
//		}
//	}
//	for (int j = 0; j < i; j++) {				// i에 기록된 test1의 인원수만큼 반복
//		fprintf(fp2, "%d %s %.1f %.1f %.1f", test1[j].num, test1[j].name, test1[j].score1, test1[j].score2, test1[j].sum);
//		if (j != i - 1)							// 마지막 행의 기록 시 엔터 미입력을 위해
//			fprintf(fp2, "\n");
//	}
//	fclose(fp1);
//	fclose(fp2);
//	free(test1);
//	return 0;
//}