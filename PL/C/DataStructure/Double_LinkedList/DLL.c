#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;			//일반 연결리스트와 다른 부분
}Node;

typedef struct _DLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void LInit(List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrevious(List* plist, Data* pdata);
int LCount(List* plist);

int main(void) {
	List list;
	int data;
	LInit(&list);
	for (int i = 1; i <= 5; i++) {
		LInsert(&list, i);
	}
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
		while (LPrevious(&list, &data)) {
			printf("%d ", data);
		}
	}
	return 0;
}

void LInit(List* plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;

	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(List* plist) {
	return plist->numOfData;
}