//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_SIZE 20
//#define IS_EMPTY(first) (!(first))
//#define MALLOC(p, s) p = malloc(s)
//
////linked list 구조체 지정
//typedef struct listNode* listPointer;
//typedef struct listNode {
//	int data;
//	listPointer link;
//};
//
//int length_chain(listPointer first);
//void fprintList(FILE* fpo, listPointer first);
//
//int main(void) {
//	FILE* fpi, * fpo;
//	char buff_str[MAX_SIZE] = { 0 };
//	char* ptr;
//	int buff_num;
//	fpi = fopen("input.txt", "r");
//	fpo = fopen("output.txt", "w");
//	int i, j, len1, len2, cnt;
//	listPointer chain1 = NULL, chain2 = NULL, result_chain = NULL;
//	listPointer curr1 = NULL, prev1 = NULL, curr2 = NULL, prev2 = NULL, curr3 = NULL, prev3 = NULL;
//
//	//input.txt로 부터 chain값 입력
//	cnt = 1;
//	while (fgets(buff_str, MAX_SIZE, fpi) != NULL) {
//		ptr = strtok(buff_str, " ");
//		while (ptr != NULL) {
//			switch (cnt) {
//			case 1:
//				buff_num = atoi(ptr);
//				ptr = strtok(NULL, " ");
//				i = buff_num;
//				MALLOC(curr1, sizeof(*curr1));
//				curr1->data = i;
//				curr1->link = NULL;
//				if (prev1 == NULL)
//					chain1 = curr1;
//				else
//					prev1->link = curr1;
//				prev1 = curr1;
//				break;
//			case 2:
//				buff_num = atoi(ptr);
//				ptr = strtok(NULL, " ");
//				i = buff_num;
//				MALLOC(curr2, sizeof(*curr2));
//				curr2->data = i;
//				curr2->link = NULL;
//				if (prev2 == NULL)
//					chain2 = curr2;
//				else
//					prev2->link = curr2;
//				prev2 = curr2;
//				break;
//			}
//		}
//		cnt++;
//	}
//	// chain연결
//	len1 = length_chain(chain1);
//	len2 = length_chain(chain2);
//	for (; chain1;chain1 = chain1->link) {
//		j = chain1->data;
//		MALLOC(curr3, sizeof(*curr3));
//		curr3->data = j;
//		curr3->link = NULL;
//		if (prev3 == NULL)
//			result_chain = curr3;
//		else
//			prev3->link = curr3;
//		prev3 = curr3;
//	}
//	for (; chain2; chain2 = chain2->link) {
//		j = chain2->data;
//		MALLOC(curr3, sizeof(*curr3));
//		curr3->data = j;
//		curr3->link = NULL;
//		if (prev3 == NULL)
//			result_chain = curr3;
//		else
//			prev3->link = curr3;
//		prev3 = curr3;
//	}
//	fprintList(fpo, result_chain);
//	fclose(fpi);
//	fclose(fpo);
//	return 0;
//	free(curr1);
//	free(curr2);
//	free(curr3);
//}
//
//int length_chain(listPointer first) {
//	int cnt = 0, length;
//	for (; first; first = first->link) {
//		cnt++;
//	}
//	length = cnt;
//	return length;
//}
//
//void fprintList(FILE* fpo,listPointer first) {
//	for (; first; first = first->link)
//		fprintf(fpo, "%d ", first->data);
//	fprintf(fpo, "\n");
//}