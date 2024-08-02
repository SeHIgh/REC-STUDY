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

typedef struct _CLL {
	Node* tail;
	Node* curr;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List* pl);
void LInsert(List* pl, Data data);
void LInsertFront(List* pl, Data data);

int LFirst(List* pl, Data* pdata);
int LNext(List* pl, Data* pdata);
Data LRemove(List* pl);
int LCount(List* pl);

int main(void) {
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);
	LInsertFront(&list, 5);
	LInsertFront(&list, 4);
	LInsertFront(&list, 3);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	

	//리스트 출력
	if (LFirst(&list, &data)) {						//연결리스트의 첫번째 노드를 찾아서 출력 및 데이터에 저장
		printf("%d ", data);

		for (i = 1; i < LCount(&list); i++) {	//연결리스트의 1 노드를 제외한 그다음 부터 출력
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	//짝수 숫자를 찾아서 제거하는 프로세스
	nodeNum = LCount(&list);

	if (nodeNum != 0) {
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 1; i < nodeNum; i++) {
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	//리스트 재출력
	if (LFirst(&list, &data)) {						//연결리스트의 첫번째 노드를 찾아서 출력 및 데이터에 저장
		printf("%d ", data);

		for (i = 1; i < LCount(&list); i++) {	//연결리스트의 1 노드를 제외한 그다음 부터 출력
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	return 0;
}

void ListInit(List* pl) {
	pl->tail = NULL;
	pl->before = NULL;
	pl->curr = NULL;
	pl->numOfData = 0;
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

void LInsertFront(List* pl, Data data) {
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
	Data rdata = rpos->data;

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