#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* link;
}Node;
typedef struct _stackLinkedList {
	Node* head;
}StackLL;
typedef StackLL Stack;

void SInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

int main(void) {
	Stack stack;
	int size;
	SInit(&stack);
	if (SIsEmpty)
		printf("스택이 비어있습니다.\n");
	printf("스택 크기 입력 : ");
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		SPush(&stack, i);
	}
	while (!SIsEmpty(&stack)) {
		printf("%d ", SPeek(&stack));
		SPop(&stack);
	}
	return 0;
}

void SInit(Stack* pstack) {
	pstack->head = NULL;
}
int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = pstack->head;
	pstack->head = newNode;
}
Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		exit(-1);
	}
	else{
		Node* delNode = pstack->head;
		Data rdata = delNode->data;

		pstack->head = pstack->head->link;
		free(delNode);
		return rdata;
	}
}
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack))
		exit(-1);
	return pstack->head->data;
}