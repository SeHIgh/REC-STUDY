#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define IS_EMPTY(first) (!(first))
#define MALLOC(p, s) p = malloc(s)

//linked list 구조체 지정
typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};

listPointer insert_chain(listPointer* first, int num, int value);
void delete_chain(listPointer* first, int num);
int length_chain(listPointer first);
void printList(listPointer first);
void chainProgram(listPointer* first);

int main(void) {
	FILE* fpi;
	fpi = fopen("input.txt", "r");
	int i, num;
	listPointer chain = NULL;
	listPointer curr = NULL, prev = NULL;

	//input.txt로 부터 chain값 입력
	while (fscanf(fpi, "%d", &num) != EOF) {
		i = num;
		MALLOC(curr, sizeof(*curr));
		curr->data = i;
		curr->link = NULL;
		if (prev == NULL)
			chain = curr;
		else
			prev->link = curr;
		prev = curr;
	}
	chainProgram(chain);
	fclose(fpi);
	return 0;
}

listPointer insert_chain(listPointer* first, int num, int value) {
	int i;
	listPointer new_node, temp;
	MALLOC(new_node, sizeof(*new_node));
	new_node->data = value;
	new_node->link = NULL;
	temp = first;
	if (num != 1)
		for (i = 0; i < num - 1; i++)		//num번째 노드 다음 삽입 이므로 num-1
			temp = temp->link;
	new_node->link = temp->link;
	temp->link = new_node;
	return first;
}

void delete_chain(listPointer* first, int num) {
	int i;
	listPointer curr = first, temp;
	MALLOC(temp, sizeof(*temp));
	if (num == 1) {
		temp = *first;
		(*first) = (*first)->link;
	}
	else {
		temp = first;
		for (i = 0; i < num - 2; i++) {
			curr = curr->link;
		}
		for (i = 0; i < num - 1; i++) {
			temp = temp->link;
		}
		curr->link = temp->link;
	}
	free(temp);
}

int length_chain(listPointer first) {
	int cnt = 0, length;
	for (; first; first = first->link) {
		cnt++;
	}
	length = cnt;
	return length;
}

void printList(listPointer first) {
	for (; first; first = first->link)
		printf("%-4d ", first->data);
	printf("\n");
}

void chainProgram(listPointer* first) {
	int menu = 1, input1, input2, TF = 1;
	listPointer x = NULL;
	listPointer curr = first;
	listPointer temp = NULL;
	listPointer prev = NULL;
	printf("chain: ");
	printList(first);
	printf("+----------------+\n");
	printf("    1. insert\n");
	printf("    2. delete\n");
	printf("    3. length\n");
	printf("    4. exit\n");
	printf("+----------------+\n\n");
	while (TF) {
		printf("Menu: ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("insert: ");
			scanf("%d %d", &input1, &input2);
			insert_chain(first, input1, input2);
			printf("result: ");
			printList(first);
			printf("\n");
			break;
		case 2:
			printf("delete: ");
			scanf("%d", &input1);
			delete_chain(first, input1);
			printf("result: ");
			printList(first);
			printf("\n");
			break;
		case 3:
			printf("length: %d\n\n", length_chain(first));
			break;
		case 4:
			printf("exit");
			TF = 0;
			break;
		}
	}
}