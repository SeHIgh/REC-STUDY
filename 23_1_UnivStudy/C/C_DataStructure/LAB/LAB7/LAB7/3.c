//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_SIZE 20
//#define IS_EMPTY(first) (!(first))
//#define MALLOC(p, s) p = malloc(s)
//#define TRUE 1
//#define FALSE 0
//
////linked list 구조체 지정
//typedef struct listNode* listPointer;
//typedef struct listNode {
//	int data;
//	listPointer link;
//};
//
//void fprintList(FILE* fp, listPointer first);
//int IsEmpty(int top);
//int IsFull(int top);
//void push(int stack[], int* top, int value);
//int pop(int stack[], int* top);
//
//int main(void) {
//	FILE* fpi, * fpo;
//	fpi = fopen("input.txt", "r");
//	fpo = fopen("output.txt", "w");
//	int i, num, top = -1;
//	int stack[MAX_SIZE] = { 0 };
//	listPointer chain = NULL;
//	listPointer curr = NULL, prev = NULL, tmp = NULL;
//
//	//input.txt로 부터 chain값 입력
//	while (fscanf(fpi, "%d", &num) != EOF) {
//		i = num;
//		MALLOC(curr, sizeof(*curr));
//		curr->data = i;
//		curr->link = NULL;
//		push(stack, &top, i);
//		if (prev == NULL)
//			chain = curr;
//		else
//			prev->link = curr;
//		prev = curr;
//	}
//	tmp = chain;
//	while (tmp != NULL) {
//		int temp = pop(stack, &top);
//		tmp->data = temp;
//		tmp = tmp->link;
//	}
//	fprintList(fpo, chain);
//	fclose(fpi);
//	fclose(fpo);
//	return 0;
//	free(curr);
//}
//
//void fprintList(FILE* fp, listPointer first) {
//	for (; first; first = first->link)
//		fprintf(fp, "%d ", first->data);
//	fprintf(fp, "\n");
//}
//
//int IsEmpty(int top) {
//	if (top < 0)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//int IsFull(int top) {
//	if (top >= MAX_SIZE - 1)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//void push(int stack[], int* top, int value) {
//	if (IsFull(*top) == FALSE) {
//		stack[++(*top)] = value;
//	}
//}
//
//int pop(int stack[], int* top) {
//	if (IsEmpty(*top) == FALSE)
//		return stack[(*top)--];
//}