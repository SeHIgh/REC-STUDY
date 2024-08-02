#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//순환 연결리스트의 기본 구조체
typedef int Data;
typedef struct _node {
	Data data;
	struct _node* next;
}Node;
typedef struct CLL {
	Node* tail;
	Node* before;
	Node* curr;
	int numOfData;
}CList;
typedef CList List;

//순환 연결리스트의 기본 함수
void LInit(List* pl);
void LFirstInsert(List* pl, Data data);
void LInsert(List* pl, Data data);
int LFirst(List* pl, Data* pdata);
int LNext(List* pl, Data* pdata);
Data LRemove(List* pl);
int LCount(List* pl);

int main(void) {
	int N, K;
	int i, len;
	Data cnt, data, rdata;
	List list;
	scanf("%d %d", &N, &K);
	
	//1~N의 값을 가지는 순환 연결리스트 생성
	LInit(&list);
	for (i = 1; i <= N; i++) {
		LInsert(&list, i);
	}

	len = LCount(&list);
	cnt = 1;
	printf("<");
	while (1) {
		if (cnt == 1) {						//탐색 시 첫번째를 우선 설정을 해둬야 탐색이 가능하므로
			for (i = 0; i < K; i++) {
				if (i == 0)
					LFirst(&list, &data);
				else
					LNext(&list, &data);
			}
		}
		else {
			//K번째 요소 제거 및 출력
			for (i = 0; i < K; i++)
				LNext(&list, &data);
		}
		rdata = LRemove(&list);
		printf("%d", rdata);

		cnt++;
		len = LCount(&list);
		if (len != 0)
			printf(", ");
		else
			break;
	}
	printf(">");
	return 0;
}

void LInit(List* pl) {
	pl->tail = NULL;
	pl->before = NULL;
	pl->curr = NULL;
	pl->numOfData = 0;
}
void LFirstInsert(List* pl, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (pl->tail == NULL) {
		pl->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = pl->tail->next;
		pl->tail->next = newNode;
	}
	(pl->numOfData)++;
}
void LInsert(List* pl, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (pl->tail == NULL) {
		pl->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = pl->tail->next;
		pl->tail->next = newNode;
		pl->tail = newNode;
	}
	(pl->numOfData)++;
}

int LFirst(List* pl, Data* pdata) {
	if (pl->tail == NULL)
		return FALSE;

	pl->before = pl->tail;
	pl->curr = pl->tail->next;

	*pdata = pl->curr->data;
	return TRUE;
}
int LNext(List* pl, Data* pdata) {
	if (pl->tail == NULL)
		return FALSE;

	pl->before = pl->curr;
	pl->curr = pl->curr->next;
	
	*pdata = pl->curr->data;
	return TRUE;
}

Data LRemove(List* pl) {
	Node* rpos = pl->curr;
	Data* rdata = rpos->data;

	if (rpos == pl->tail) {
		if (pl->tail == pl->tail->next)
			pl->tail = NULL;
		else
			pl->tail = pl->before;
	}
	pl->before->next = pl->curr->next;
	pl->curr = pl->before;

	free(rpos);
	(pl->numOfData)--;
	return rdata;
}

int LCount(List* pl) {
	return pl->numOfData;
}