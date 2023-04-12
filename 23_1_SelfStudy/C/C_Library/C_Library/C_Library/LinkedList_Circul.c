#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) p = malloc(s)

//���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct listNode {
	int data;
	linkedList* link;
}linkedList;

linkedList* createHead(void);								// ���� ���� ����Ʈ�� ��� ��带 �����ϴ� ����
void printLinkedList(linkedList* h);						// ���� ���� ����Ʈ�� ����ϴ� ����
void insertFirstNode(linkedList* h, int data);				// ���� ���� ����Ʈ�� ù ��° ��带 �����ϴ� ����
void insertNode(linkedList* h, linkedList* pre, int data);	// ���� ���� ����Ʈ�� �߰� ��带 �����ϴ� ����
void deleteNode(linkedList* h, linkedList* target);		// ���� ���� ����Ʈ�� ��带 �����ϴ� ����
linkedList* searchNode(linkedList* h, int find);			// ���� ���� ����Ʈ���� ��带 Ž���ϴ� ����

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
	linkedList* pre;				// ������ ����� ������ ��带 ��Ÿ���� ������	
	if (h == NULL) return;		// ���� ����Ʈ�� ���, ���� ���� �ߴ�	
	if (h->link == h) {		// ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(h);			  // ù ��° ����� �޸𸮸� �����ϰ�
		h = NULL;			  // ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (target == NULL) return;   		// ������ ��尡 ���� ���, ���� ���� �ߴ�	
	else {
		pre = h;			// ������ pre�� ����Ʈ�� ���� ��忡 ����		
		while (pre->link != target) {
			pre = pre->link;		// ������ ��带 ������ pre�� �̿��� ã��
		}
		pre->link = target->link;
		if (target == h)
			h = target->link;
		free(target);				// ���� ����� �޸𸮸� ����	 		
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