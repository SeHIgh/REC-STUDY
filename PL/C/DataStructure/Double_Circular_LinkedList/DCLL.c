#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1	
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* rlink;
	struct _node* llink;
}Node;

typedef struct _DoubleCircularLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
}DCLList;

typedef DCLList List;

void LInit(List* plist);							//생성
void LInsert(List* plist, Data data);
void LInsert_Middle(List* plist, Node* pprev, Data data);	//삽입(특정 노드의 뒤)
void LDelete(List* plist, Node* pdel);				//삭제

int LFirst(List* plist, Data* pdata);	//처음 위치의 data를 반환
int LNext(List* plist, Data* pdata);	//다음 위치의 data를 반환
int LCount(List* plist);				//List를 구성하는 노드의 개수 반환 

Node* LSearch(List* plist, Data data);	//특정 data를 가지는 노드를 탐색 및 주소 반환 

int main(void) {
	Data data = 0, fdata = 0;
	List list;
	Node* find;

	LInit(&list);
	for (int i = 1; i <= 5; i++)
		LInsert(&list, i);

	if (LFirst(&list, &data)) {
		printf("%d ",data);
		while (LNext(&list, &data)) {
			if (list.cur != list.head)					//circular이기 때문에 일반 양방향연결리스트 출력을 쓰면, 무한정 루프를 돌게됨. 따라서, cur이 head를 만나면 중지하도록 설정.
				printf("%d ", data);
			else
				break;
		}
	}
	printf("삭제 하고자 하는 수를 입력하시오 : ");
	scanf("%d", &fdata);
	find = LSearch(&list, fdata);

	LDelete(&list, find);

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			if (list.cur != list.head)
				printf("%d ", data);
			else
				break;
		}
	}

	printf("삽입 하고자 하는 위치(a -> a뒤)와 수를 입력하시오 : ");
	scanf("%d %d", &fdata, &data);
	find = LSearch(&list, fdata);
	LInsert_Middle(&list, find, data);
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			if (list.cur != list.head)
				printf("%d ", data);
			else
				break;
		}
	}
	return 0;
}

void LInit(List* plist) {
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->head == NULL) {
		newNode->llink = newNode;
		newNode->rlink = newNode;
		plist->head = newNode;
	}
	else {												//헤드의 왼쪽(리스트의 맨 끝에 삽입한다 생각)
		newNode->llink = plist->head->llink;
		newNode->rlink = plist->head;
		plist->head->llink->rlink = newNode;
		plist->head->llink = newNode;
	}
	(plist->numOfData)++;
}

void LInsert_Middle(List* plist, Node* pprev, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->head == NULL) {					//선행 노드가 존재하지 않는 경우(탐색 함수에서 만져줘야함) -> pprev == list->head
		newNode->llink = newNode;
		newNode->rlink = newNode;
		plist->head = newNode;
	}
	else {
		newNode->rlink = pprev->rlink;
		newNode->llink = pprev;
		pprev->rlink->llink = newNode;
		pprev->rlink = newNode;
	}
	(plist->numOfData)++;
}
void LDelete(List* plist, Node* pdel) {				//삭제	//문제점 : head 노드를 삭제 할때 오류가 생김
	if (pdel != NULL) {
		pdel->llink->rlink = pdel->rlink;
		pdel->rlink->llink = pdel->llink;
	}
	if (pdel == plist->head) {								//해결방법!
		plist->head = pdel->rlink;							//헤더 노드가 삭제되서 생기는 문제, 헤더노드를 그다음노드로 지정
	}
	free(pdel);

	(plist->numOfData)--;
}

int LFirst(List* plist, Data* pdata) {	//처음 위치의 data를 반환
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata) {	//다음 위치의 data를 반환
	if (plist->cur->rlink == NULL)
		return FALSE;

	plist->cur = plist->cur->rlink;

	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {	//다음 위치의 data를 반환
	if (plist->cur->llink == NULL)
		return FALSE;

	plist->cur = plist->cur->llink;

	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(List* plist) {				//List를 구성하는 노드의 개수 반환 
	return plist->numOfData;
}

Node* LSearch(List* plist, Data fdata) {	//특정 data를 가지는 노드를 탐색 및 주소 반환
	Node* Find;
	Find = plist->cur;
	if (plist->head == NULL)
		return Find;
	while (Find->data != fdata) {
		Find = Find->rlink;
	}
	return Find;
}