#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct {
	int queue[MAX_SIZE];
	int front;
	int rear;
}Queue;

int Q_Empty(void);
void Q_Full(void);
void Add_Q(Queue* q);
int Delete_Q(Queue* q);
void print_Q(Queue q);
void print_MainMenu(void);
void select_menu(Queue* q);
void Queue_Management(void);

int main(void) {
	Queue_Management();
	return 0;
}

int Q_Empty(void) {
	return FALSE;
}

void Q_Full(void) {
	printf("Error!\n");
}

void Add_Q(Queue* q) {
	int num;
	if (q->rear == MAX_SIZE - 1)
		Q_Full();
	else {
		printf("AddQ Data : ");
		scanf("%d", &num);
		q->queue[++(q->rear)] = num;
	}
}

int Delete_Q(Queue* q) {
	if (q->front == q->rear)
		return Q_Empty();
	else
		return q->queue[++(q->front)];
}

void print_Q(Queue q) {
	if (q.front != q.rear) {
		printf("List : ");
		for (int i = (q.front) + 1; i <= q.rear; i++) {
			printf("%d", q.queue[i]);
			if (i < q.rear)
				printf(" ");
			else
				printf("\n");
		}
	}
}

void print_MainMenu(void) {
	printf("*********************************\n");
	printf("* 1. AddQ\t\t\t*\n");
	printf("* 2. DeleteQ\t\t\t*\n");
	printf("* 3. List\t\t\t*\n");
	printf("* 4. Exit\t\t\t*\n");
	printf("*********************************\n");
}

void select_menu(Queue* q) {
	int menu = 1, temp;
	while (menu != 4) {
		print_MainMenu();
		printf("Menu : ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			Add_Q(q);
			break;
		case 2:
			temp = Delete_Q(q);
			if (temp != FALSE)
				printf("DeleteQ Data : %d\n", temp);
			else
				printf("Error!\n");
			break;
		case 3:
			print_Q(*q);
			break;
		}
	}
	printf("Exit\n");
}

void Queue_Management(void) {
	Queue q;
	q.front = -1; q.rear = -1;
	Queue* ptr = &q;
	select_menu(ptr);
}