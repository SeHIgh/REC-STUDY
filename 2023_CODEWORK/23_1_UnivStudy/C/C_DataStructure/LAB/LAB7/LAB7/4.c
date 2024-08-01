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
//typedef struct {
//	listPointer top;
//}linkedStack;
//
//void init(linkedStack* stack);
//int IsEmpty(linkedStack* stack);
//int IsFull(linkedStack* stack);
//void push(linkedStack* stack, int value);
//int pop(linkedStack* stack);
//void fprintStack(FILE* fp, linkedStack* stack);
//
//int main(void) {
//	int num;
//	FILE* fpi, * fpo;
//	fpi = fopen("input.txt", "r");
//	fpo = fopen("output.txt", "w");
//	linkedStack stack;
//	init(&stack);
//
//	//input.txt로 부터 stack 값 입력
//	while (fscanf(fpi, "%d", &num) != EOF) {
//		push(&stack, num);
//	}
//	fprintStack(fpo, &stack);
//	fclose(fpi);
//	fclose(fpo);
//	return 0;
//}
//
//void init(linkedStack* stack) {
//	stack->top = NULL;
//}
//
//int IsEmpty(linkedStack* stack) {
//	return(stack->top = NULL);
//}
//
//int IsFull(linkedStack* stack) {
//	return 0;
//}
//
//void push(linkedStack* stack, int value) {
//	listPointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->data = value;
//	temp->link = stack->top;
//	stack->top = temp;
//}
//
//int pop(linkedStack* stack) {
//		listPointer temp = stack->top;
//		int data = temp->data;
//		stack->top = stack->top->link;
//		free(temp);
//		return data;
//}
//
//void fprintStack(FILE* fp, linkedStack* stack) {
//	while (stack->top != NULL) {
//		fprintf(fp, "%d ", pop(stack));
//	}
//}