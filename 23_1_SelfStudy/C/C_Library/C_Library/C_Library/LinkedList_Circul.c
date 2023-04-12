#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) p = malloc(s)

//원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct listNode {
	int data;
	linkedList* link;
}linkedList;

linkedList* createHead(void);								// 원형 연결 리스트의 헤드 노드를 생성하는 연산
void printLinkedList(linkedList* h);						// 원형 연결 리스트를 출력하는 연산
void insertFirstNode(linkedList* h, int data);				// 원형 연결 리스트의 첫 번째 노드를 삽입하는 연산
void insertNode(linkedList* h, linkedList* pre, int data);	// 원형 연결 리스트의 중간 노드를 삽입하는 연산
void deleteNode(linkedList* h, linkedList* target);		// 원형 연결 리스트의 노드를 삭제하는 연산
linkedList* searchNode(linkedList* h, int find);			// 원형 연결 리스트에서 노드를 탐색하는 연산

int main(void) {
	linkedList* head;
	createHead();
	insertFirstNode(head, 10);
	insertLastNode(head, 20);
	insertLastNode(head, 30);
	insertNode(head, searchNode(head, 20), 25);
	printLinkedList(head);
	deleteNode(head, searchNode(head, 20));
	printLinkedList(head);
	return 0;
}

linkedList* createHead(void) {
	linkedList* h;
	MALLOC(h, sizeof(*h));
	h = NULL;
	return h;
}

void printLinkedList(linkedList* h) {
	linkedList* p;
	printf(" h = (");
	p = h;
	do {
		printf("%d", p->data);
		p = p->link;
		if (p != h) printf(", ");
	} while (p != h);
	printf(") \n");
}

void insertFirstNode(linkedList* h, int data) {
	linkedList* newNode;
	MALLOC(newNode, sizeof(*newNode));
	newNode->data = data;
	if (h == NULL) {
		h = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = h->link;
		h->link = newNode;
	}
}

void insertNode(linkedList* h, linkedList* pre, int data) {
	linkedList* newNode;
	MALLOC(newNode, sizeof(*newNode));
	newNode->data = data;
	if (h == NULL) {
		h = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList* h, int data) {
	linkedList* newNode;
	MALLOC(newNode, sizeof(*newNode));
	newNode->data = data;
	if (h == NULL) {
		h = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = h->link;
		h->link = newNode;
		h = newNode;
	}
}

void deleteNode(linkedList* h, linkedList* target) {
	linkedList* pre;				// 삭제할 노드의 선행자 노드를 나타내는 포인터	
	if (h == NULL) return;		// 공백 리스트인 경우, 삭제 연산 중단	
	if (h->link == h) {		// 리스트에 노드가 한 개만 있는 경우
		free(h);			  // 첫 번째 노드의 메모리를 해제하고
		h = NULL;			  // 리스트 시작 포인터를 NULL로 설정
		return;
	}
	else if (target == NULL) return;   		// 삭제할 노드가 없는 경우, 삭제 연산 중단	
	else {
		pre = h;			// 포인터 pre를 리스트의 시작 노드에 연결		
		while (pre->link != target) {
			pre = pre->link;		// 선행자 노드를 포인터 pre를 이용해 찾음
		}
		pre->link = target->link;
		if (target == h)
			h = target->link;
		free(target);				// 삭제 노드의 메모리를 해제	 		
	}
}

linkedList* searchNode(linkedList* h, int find) {
	linkedList* temp;
	temp = h;
	if (temp == NULL) return NULL;
	do {
		if ((temp = find) == 0) return temp;
		else temp = temp->link;
	} while (temp != h);
	return NULL;
}