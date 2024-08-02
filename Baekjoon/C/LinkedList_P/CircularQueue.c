#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* next;
}Node;
typedef struct lQueue {
	Node* front;
	Node* rear;
}LQueue;
typedef LQueue Queue;

//ť�� �⺻ �Լ�
void QInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq, Data data);
int Dequeue(Queue* pq);
int QPeek(Queue* pq);
//������ �־��� ����
void QshiftLeft(Queue* pq);
void QshiftRight(Queue* pq);
//�߰��� �ʿ��� �Լ�
int Qsearch(Queue* pq, Data find);
void printQ(Queue* pq);

int main(void) {
	//N : ť�� ����, M : �̾Ƴ� �� ����
	int N, M, Qlen, cnt = 0;		// N <= 50, N >= M
	int* find, findidx, i;
	Queue q;
	QInit(&q);
	//���� �Է�
	scanf("%d %d", &N, &M);
	find = (int*)malloc(sizeof(int) * M);
	//ã�� �� temp �迭�� ����
	for (i = 0; i < M; i++)
		scanf("%d", &find[i]);
	//ť�� 1~N���� �Է�
	for (i = 1; i <= N; i++) {
		Enqueue(&q, i);
	}

	//������ �ּڰ� ��� ���α׷�
	Qlen = N;
	for (i = 0; i < M; i++) {
		while (QPeek(&q) != find[i]) {
			findidx = Qsearch(&q, find[i]);
			//���� ť ���̰� Ȧ�� �϶�, ã�� ���� �߰��� �ִ� ��� Rightshift�� �ع����� ������ Ȧ¦ ��츦 ������ ���ش�.
			if (Qlen % 2 != 0) {
				if ((Qlen / 2) + 1 >= findidx) {
					QshiftLeft(&q);
					cnt++;
				}
				else {
					QshiftRight(&q);
					cnt++;
				}
			}
			else {
				if ((Qlen / 2) >= findidx) {
					QshiftLeft(&q);
					cnt++;
				}
				else {
					QshiftRight(&q);
					cnt++;
				}
			}

		}
		Dequeue(&q);
		Qlen--;
	}
	//�ּڰ� ���
	printf("%d", cnt);
	free(find);
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
		printf("Queue Memory Error!\n");
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
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	return pq->front->data;
}

void QshiftLeft(Queue* pq) {
	Node* frontNode = (Node*)malloc(sizeof(Node));
	Data Front;
	Front = pq->front->data;
	frontNode->next = NULL;
	frontNode->data = Front;
	Dequeue(pq);
	pq->rear->next = frontNode;
	pq->rear = frontNode;
}

void QshiftRight(Queue* pq) {
	Node* rearNode = (Node*)malloc(sizeof(Node));
	Node* preNode = pq->front;
	Data Rear;
	//rear����� �� ��� Ž��
	while (preNode->next != pq->rear)
		preNode = preNode->next;

	Rear = pq->rear->data;
	//front�� rear�� data�� ��ȯ
	rearNode->data = Rear;
	rearNode->next = pq->front;
	pq->front = rearNode;
	//rear��带 �� ���� �ű�� ���� �ڸ��� NULL�ʱ�ȭ
	pq->rear = preNode;
	pq->rear->next = NULL;
}

int Qsearch(Queue* pq, Data find) {
	int cnt = 1;
	Node* Find = pq->front;
	while (Find->next != NULL) {
		if (Find->data == find)
			break;
		Find = Find->next;
		cnt++;
	}
	return cnt;
}

void printQ(Queue* pq) {
	Node* temp = pq->front;
	printf("Q : { ");
	while (temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("}\n");
}