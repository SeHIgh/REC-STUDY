#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _Arraystack {
	Data data[MAXSIZE];
	int top;
}ArrStack;
typedef ArrStack Stack;

void SInit(Stack* stack);
int SIsEmpty(Stack* stack);
int SIsFull(Stack* stack);
void SPush(Stack* stack, int input);
int SPop(Stack* stack);
void SPrint(Stack* stack);
Data SPeek(Stack* stack);

int main(void) {
	int n;
	Stack stack;
	SInit(&stack);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		SPush(&stack, i);
	SPrint(&stack);

	printf("STACK : {");
	while (!SIsEmpty(&stack)) {
		printf("%d", SPop(&stack));
		if (stack.top > -1)
			printf(", ");
		else
			printf("}\n");
	}
	return 0;
}

void SInit(Stack* stack) {
	stack->top = -1;
}
int SIsEmpty(Stack* stack) {
	if (stack->top == -1)
		return TRUE;
	else
		return FALSE;
}
int SIsFull(Stack* stack) {
	if (stack->top == MAXSIZE)
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack* stack, int input) {
	if (SIsFull(stack)) {
		printf("(오류) 스택의 여유 공간이 없습니다.\n");
	}
	else {
		int* idx = &stack->top;
		stack->data[++(*idx)] = input;
	}
}
int SPop(Stack* stack) {
	if (SIsEmpty(stack)) {
		printf("(오류) 스택이 비어있습니다.\n");
		return -1;
	}
	else {
		int* idx = &stack->top;
		int popdata = stack->data[(*idx)--];
		return popdata;
	}
}
void SPrint(Stack* stack) {
	if (SIsEmpty(stack))
		printf("(오류) 스택이 비어있습니다.\n");
	else {
		printf("STACK : {");
		for (int i = 0; i <= stack->top; i++) {
			printf("%d", stack->data[i]);
			if (i < stack->top)
				printf(", ");
			else
				printf("}\n");
		}
	}
}

Data SPeek(Stack* stack) {
	return stack->data[stack->top];
}