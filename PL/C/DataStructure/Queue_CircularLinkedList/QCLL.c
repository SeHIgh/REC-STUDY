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
typedef struct QueueCircularLinkdeList {
	Node* rear;
}QCLL;
typedef QCLL Queue;

void QInit(Queue* pq);
int QIsEmpty(Queue* pq);
void QAdd(Queue* pq, Data data);
Data QDelete(Queue* pq);
Data QPeek(Queue* pq);
void QPrint(Queue* pq);

int main(void)
{
	int size;
	Queue q;
	QInit(&q);
	printf("큐의 크기 입력 : ");
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		QAdd(&q, i);
	}
	QPrint(&q);
	return 0;
}

void QInit(Queue* pq) {
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq) {
	if (pq->rear == NULL)
		return TRUE;
	else
		return FALSE;
}
void QAdd(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (QIsEmpty(pq)) {
		pq->rear = newNode;
		pq->rear->link = pq->rear;
	}
	else {
		newNode->link = pq->rear->link;
		pq->rear->link = newNode;
	}
}
Data QDelete(Queue* pq) {
	Node* delNode = pq->rear;
	Data rdata;
	if (!QIsEmpty(pq)) {
		rdata = delNode->data;
		pq->rear = pq->rear->link;
		free(delNode);
		return rdata;
	}
}
Data QPeek(Queue* pq) {
	if (!QIsEmpty(pq))
		return pq->rear->link->data;
}
void QPrint(Queue* pq) {
	if (!QIsEmpty(pq)) {
		printf("Queue : {");
		while (!QIsEmpty(pq)) {
			printf("%d", QDelete(pq));
			if (!QIsEmpty(pq))
				printf(", ");
			else
				printf("}\n");
		}
	}
}