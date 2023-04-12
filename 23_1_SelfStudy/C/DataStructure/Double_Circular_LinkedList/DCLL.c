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

void LInit(List* plist);							//����
void LInsert(List* plist, Data data);
void LInsert_Middle(List* plist, Node* pprev, Data data);	//����(Ư�� ����� ��)
void LDelete(List* plist, Node* pdel);				//����

int LFirst(List* plist, Data* pdata);	//ó�� ��ġ�� data�� ��ȯ
int LNext(List* plist, Data* pdata);	//���� ��ġ�� data�� ��ȯ
int LCount(List* plist);				//List�� �����ϴ� ����� ���� ��ȯ 

Node* LSearch(List* plist, Data data);	//Ư�� data�� ������ ��带 Ž�� �� �ּ� ��ȯ 

int main(void) {
	Data data = 0, fdata = 0;
	List list;
	Node* find = LSearch(&list, fdata);

	LInit(&list);
	for (int i = 1; i <= 5; i++)
		LInsert(&list, i);

	if (LFirst(&list, &data)) {
		printf("%d ",data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}

	scanf("%d", &fdata);
	find = LSearch(&list, fdata);

	LDelete(&list, find);

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
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
		exit(-1);
	}

	newNode->llink = plist->head;
	newNode->rlink = plist->head;
	plist->head = newNode;

	(plist->numOfData)++;
}

void LInsert_Middle(List* plist, Node* pprev, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->head == NULL) {					//���� ��尡 �������� �ʴ� ���(Ž�� �Լ����� ���������) -> pprev == list->head
		printf("����1");
		newNode->llink = newNode;
		newNode->rlink = newNode;
		plist->head = newNode;
		printf("����1\n");
		exit(-1);
	}
	printf("����2\n");
	newNode->rlink = pprev->rlink;
	newNode->llink = pprev;
	pprev->rlink->llink = newNode;
	pprev->rlink = newNode;
	printf("����2\n");
	(plist->numOfData)++;
}
void LDelete(List* plist, Node* pdel) {				//����
	if (pdel != NULL) {
		pdel->llink->rlink = pdel->rlink;
		pdel->rlink->llink = pdel->llink;
	}
	free(pdel);

	(plist->numOfData)--;
}

int LFirst(List* plist, Data* pdata) {	//ó�� ��ġ�� data�� ��ȯ
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata) {	//���� ��ġ�� data�� ��ȯ
	if (plist->cur->rlink == NULL)
		return FALSE;

	plist->cur = plist->cur->rlink;

	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {	//���� ��ġ�� data�� ��ȯ
	if (plist->cur->llink == NULL)
		return FALSE;

	plist->cur = plist->cur->llink;

	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(List* plist) {				//List�� �����ϴ� ����� ���� ��ȯ 
	return plist->numOfData;
}

Node* LSearch(List* plist, Data fdata) {	//Ư�� data�� ������ ��带 Ž�� �� �ּ� ��ȯ
	Node* Find;
	Find = plist->cur;
	if (fdata == 0) {
		return Find;
	}
	while (Find->data != fdata) {
		Find = Find->rlink;
	}
	return Find;
}