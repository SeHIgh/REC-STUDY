#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//DataŸ�� ����
typedef int Data;
//���Ḯ��Ʈ Node����
typedef struct _node {
	Data data;
	struct _node* next;
}Node;
//ť ����ü
typedef struct lQueue {
	Node* front;
	Node* rear;
}LQueue;
//Queue�� ����ȭ
typedef LQueue Queue;

void QInit(Queue* pq);				//��ȯ ť ����
int QIsEmpty(Queue* pq);			//��ȯ ť�� ����ִ��� Ȯ��
void Enqueue(Queue* pq, Data data);	//ť�� ������ �߰�
int Dequeue(Queue* pq);				//ť ������ ��ȯ �� ����
int QPeek(Queue* pq);				//ť�� ���� ������ Ȯ�� (ť ���� X)

int main(void) {
	Queue q;
	QInit(&q);

	Enqueue(&q, 10); Enqueue(&q, 20);
	Enqueue(&q, 30); Enqueue(&q, 40);

	printf("Queue : ");
	do
	{
		printf("%d ", Dequeue(&q));

	} while (!QIsEmpty(&q));
	printf("\n");
	return 0;
}

void QInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

int Dequeue(Queue* pq) {
	Node* delNode;
	Data retdata;
	if (QIsEmpty(pq)) {
		printf("Error : Queue memory Empty!\n");
		exit(-1);
	}
	delNode = pq->front;
	retdata = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retdata;
}

int QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Error : Queue memory Empty!\n");
		exit(-1);
	}
	return pq->front->data;
}