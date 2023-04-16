#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* llink;
	struct _node* rlink;
}Node;
typedef struct DoubleLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
}DList;
typedef DList List;

//이중 순환 연결 리스트 기본 함수
void LInit(List* plist);
void LInsert_First(List* plist, Data data);
void LInsert_Middle(List* plist, Node* prev, Data data);
void LDelete(List* plist, Data data);
int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LCount(List* plist);
Node* LSearch(List* plist, Data data);
void LPrint(List* plist, Data* pdata);

//문제 필요 함수
void LgoFront(List* plist, Data move, Data stay);
void LgoBehind(List* plist, Data move, Data stay);

int main(void) {
	int N, M;	// N:노드의 수, M:연산의 수
	int data = 0; //move, stay;
	//char AB;
	List list;
	LInit(&list);

	scanf("%d %d", &N, &M);
	//getchar();
	for (int i = 1; i <= N; i++) {
		LInsert_First(&list, i);
	}

	/*scanf("%c %d %d", &AB, &move, &stay);
	printf("%c %d %d", AB, move, stay);*/
	//LgoBehind(&list, 1, 4);
	//printf("성공\n");
	LInsert_Middle(&list, LSearch(&list, 3), 7);
	LPrint(&list, &data);

	//for (int i = 0; i < M; i++) {
	//	scanf("%c %d %d", &Sel, &move, &stay);
	//	if (Sel == 'A') {
	//		LgoFront(&list, move, stay);
	//		LPrint(&list, &data);
	//	}
	//	else if (Sel == 'B') {
	//		LgoBehind(&list, move, stay);
	//		LPrint(&list, &data);
	//	}
	//	//LPrint(&list, &data);
	//}
	//LPrint(&list, &data);
	return 0;
}

void LInit(List* plist) {
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}
void LInsert_First(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->head == NULL) {
		newNode->llink = newNode;
		newNode->rlink = newNode;
		plist->head = newNode;
	}
	else {
		newNode->llink = plist->head->llink;
		newNode->rlink = plist->head;
		plist->head->llink->rlink = newNode;
		plist->head->llink = newNode;
	}
	(plist->numOfData)++;
}

void LInsert_Middle(List* plist, Node* prev, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->head == NULL) {
		newNode->llink = newNode;
		newNode->rlink = newNode;
		plist->head = newNode;
	}
	else {
		newNode->llink = prev;
		newNode->rlink = prev->rlink;
		prev->rlink->llink = newNode;
		prev->rlink = newNode;
	}
	(plist->numOfData)++;
}

void LDelete(List* plist, Data data) {
	Node* delNode, * find;
	find = LSearch(plist, data);
	delNode = find;
	if (delNode != NULL) {
		delNode->llink->rlink = delNode->rlink;
		delNode->rlink->llink = delNode->llink;
	}
	if (delNode == plist->head) {
		plist->head = delNode->rlink;
	}
	free(delNode);
	(plist->numOfData)--;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->head == NULL)
		return FALSE;
	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->rlink == NULL)
		return FALSE;
	plist->cur = plist->cur->rlink;

	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->llink == NULL)
		return FALSE;
	plist->cur = plist->cur->rlink;

	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(List* plist) {
	return plist->numOfData;
}

Node* LSearch(List* plist, Data data) {
	Node* find = plist->cur;
	if (plist->head == NULL)
		return find;

	while (find->data != data) {
		find = find->rlink;
	}
	return find;
}

void LPrint(List* plist, Data* pdata) {
	if (LFirst(plist, pdata)) {
		printf("%d ", *pdata);
		while (plist->cur->rlink != plist->head) {
			LNext(plist, pdata);
			printf("%d ", *pdata);
		}
	}
	printf("\n");
}

void LgoFront(List* plist, Data move, Data stay) {
	LDelete(plist, move);
	if (stay - 1 == 0)
		LInsert_Middle(plist, LSearch(plist, plist->head->llink->data), move);
	else
		LInsert_Middle(plist, LSearch(plist, stay - 1), move);
}

void LgoBehind(List* plist, Data move, Data stay) {
	LDelete(plist, move);
	LInsert_Middle(plist, LSearch(plist, stay), move);
}