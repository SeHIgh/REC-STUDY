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
//	testlist* test1 = (testlist*)calloc(cnt, sizeof(testlist));		//���� �ջ��� 0���� �ʱ�ȭ ���ѵα�����
//	testlist* buff;													//�ӽ� ����ü ���� ����
//	fp1 = fopen("input.txt", "r");
//	fp2 = fopen("output.txt", "w");
//	i = 0;
//	while (fscanf(fp1, "%d %s %f %f", &test1[i].num, &test1[i].name, &test1[i].score1, &test1[i].score2) != EOF) {
//		test1[i].sum = test1[i].score1 + test1[i].score2;
//		i++;
//		buff = realloc(test1, sizeof(testlist) * (++cnt));			//�޸� ���Ҵ� �� ���� �޸��� ������ �� ���Ҵ� ���� �ø� ��� �ӽ� ����ü�� �ּ� ���� 
//		if (buff != NULL) {
//			test1 = buff;											//NULL���� �ƴ� �� ������ ó��
//		}
//	}
//	for (int j = 0; j < i; j++) {				// i�� ��ϵ� test1�� �ο�����ŭ �ݺ�
//		fprintf(fp2, "%d %s %.1f %.1f %.1f", test1[j].num, test1[j].name, test1[j].score1, test1[j].score2, test1[j].sum);
//		if (j != i - 1)							// ������ ���� ��� �� ���� ���Է��� ����
//			fprintf(fp2, "\n");
//	}
//	fclose(fp1);
//	fclose(fp2);
//	free(test1);
//	return 0;
//}