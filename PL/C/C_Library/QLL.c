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
typedef struct QLinkedList {
	Node* head;
	Node* rear;
}QLL;
typedef QLL Queue;

void QInit(Queue* pq);
int QIsEmpty(Queue* pq);
void QAdd(Queue* pq, Data data);
Data QDelete(Queue* pq);
Data QPeek(Queue* pq);
void QPrint(Queue* pq);

int main(void) {
	int size;
	Queue q;
	QInit(&q);
	printf("큐 사이즈 입력 : ");
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		QAdd(&q, i);
	}
	QPrint(&q);
	QDelete(&q);

	return 0;
}

void QInit(Queue* pq) {
	pq->head = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq) {
	if (pq->head == NULL)
		return TRUE;
	else
		return FALSE;
}
void QAdd(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->link = NULL;
	newNode->data = data;
	if (QIsEmpty(pq)) {
		pq->head = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->link = newNode;
		pq->rear = newNode;
	}
}
Data QDelete(Queue* pq) {
	Node* delNode = pq->head;
	Data rdata;
	if (!QIsEmpty(pq)) {
		rdata = delNode->data;
		pq->head = pq->head->link;
		free(delNode);
		return rdata;
	}
}
Data QPeek(Queue* pq) {
	return pq->head->data;
}
void QPrint(Queue* pq) {
	if (pq->head != NULL) {
		Node* temp = pq->head;
		printf("Queue : {");
		while (temp != NULL) {
			printf("%d", temp->data);
			temp = temp->link;
			if (temp != NULL)
				printf(", ");
			else
				printf("}\n");
		}
	}
}