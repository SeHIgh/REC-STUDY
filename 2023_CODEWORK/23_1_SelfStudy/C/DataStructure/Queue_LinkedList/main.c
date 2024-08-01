#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//Data타입 지정
typedef int Data;
//연결리스트 Node생성
typedef struct _node {
	Data data;
	struct _node* next;
}Node;
//큐 구조체
typedef struct lQueue {
	Node* front;
	Node* rear;
}LQueue;
//Queue로 간소화
typedef LQueue Queue;

void QInit(Queue* pq);				//순환 큐 생성
int QIsEmpty(Queue* pq);			//순환 큐가 비어있는지 확인
void Enqueue(Queue* pq, Data data);	//큐에 데이터 추가
int Dequeue(Queue* pq);				//큐 데이터 반환 및 삭제
int QPeek(Queue* pq);				//큐의 다음 데이터 확인 (큐 변동 X)

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