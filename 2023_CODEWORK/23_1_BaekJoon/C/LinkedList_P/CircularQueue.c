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

//큐의 기본 함수
void QInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq, Data data);
int Dequeue(Queue* pq);
int QPeek(Queue* pq);
//문제에 주어진 연산
void QshiftLeft(Queue* pq);
void QshiftRight(Queue* pq);
//추가로 필요한 함수
int Qsearch(Queue* pq, Data find);
void printQ(Queue* pq);

int main(void) {
	//N : 큐의 개수, M : 뽑아낼 수 개수
	int N, M, Qlen, cnt = 0;		// N <= 50, N >= M
	int* find, findidx, i;
	Queue q;
	QInit(&q);
	//정보 입력
	scanf("%d %d", &N, &M);
	find = (int*)malloc(sizeof(int) * M);
	//찾을 수 temp 배열에 저장
	for (i = 0; i < M; i++)
		scanf("%d", &find[i]);
	//큐에 1~N까지 입력
	for (i = 1; i <= N; i++) {
		Enqueue(&q, i);
	}

	//연산의 최솟값 출력 프로그램
	Qlen = N;
	for (i = 0; i < M; i++) {
		while (QPeek(&q) != find[i]) {
			findidx = Qsearch(&q, find[i]);
			//만약 큐 길이가 홀수 일때, 찾는 수가 중간에 있는 경우 Rightshift를 해버리기 때문에 홀짝 경우를 나눠서 해준다.
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
	//최솟값 출력
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
	//rear노드의 전 노드 탐색
	while (preNode->next != pq->rear)
		preNode = preNode->next;

	Rear = pq->rear->data;
	//front를 rear의 data로 변환
	rearNode->data = Rear;
	rearNode->next = pq->front;
	pq->front = rearNode;
	//rear노드를 전 노드로 옮기고 원래 자리를 NULL초기화
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