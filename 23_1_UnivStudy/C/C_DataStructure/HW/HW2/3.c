#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 20*2
#define BLACK 0
#define WHITE 1


int IsEmpty(int top);
int IsFull(int top);
void push(int stack[], int* top, int value);
int pop(int stack[], int* top);
int make_randnum(void);
void marble_input(int stack[], int* top);
void marble_result(int stack[], int* top);
void marble_Program(void);

int main(void) {
	marble_Program();
	return 0;
}

int IsEmpty(int top) {
	if (top < 0)
		return TRUE;
	else
		return FALSE;
}

int IsFull(int top) {
	if (top >= MAX_SIZE - 1)
		return TRUE;
	else
		return FALSE;
}

void push(int stack[], int* top, int value) {
	if (IsFull(*top) == FALSE) {
		stack[++(*top)] = value;
	}
}

int pop(int stack[], int* top) {
	if (IsEmpty(*top) == FALSE)
		return stack[(*top)--];
}

int make_randnum(void) {
	int temp;
	temp = rand() % 2;
	return temp;
}

void marble_input(int stack[], int* top) {
	int temp;
	temp = make_randnum();

	if (temp == BLACK)
		printf("검");
	else if (temp == WHITE)
		printf("흰");

	if (temp == BLACK)
		for (int i = 0; i < 2; i++)
			push(stack, top, BLACK);
	else if (temp == WHITE) {
		for (int i = 0; i < 2; i++) {
			if (!IsEmpty(*top))
				pop(stack, top);
			else
				break;
		}
		push(stack, top, WHITE);
	}
}

void marble_result(int stack[], int* top) {
	int marble, white_marble = 0, black_marble = 0;
	while (!IsEmpty(*top)) {
		marble = pop(stack, top);
		if (marble == BLACK)
			black_marble++;
		else if (marble == WHITE)
			white_marble++;
	}
	printf("\n결과\n");
	printf("하얀색 구슬: %d개\n", white_marble);
	printf("검은색 구슬: %d개\n", black_marble);
}

void marble_Program(void) {
	srand((unsigned)time(NULL));
	int num, stack[MAX_SIZE] = { 0 };
	int i, top = -1;
	char replay;
	printf("\n*********************************************\n");
	printf("구슬 개수를 입력하세요 : ");
	scanf("%d", &num);
	getchar();
	i = 0;
	printf("생성된 구슬 : ");
	while ((i < num) && (!IsFull(top))) {
		marble_input(stack, &top);
		if(i<num-1)
			printf(" ");
		else
			printf("\n");
		i++;
	}
	printf("주머니에 구슬을 넣었습니다.\n\n");
	marble_result(stack, &top);
	printf("다시 하겠습니까? [y/n] : ");
	scanf("%c", &replay);
	if (replay == 'y')
		marble_Program();
	else if (replay == 'n')
		printf("\n프로그램을 종료합니다.\n");
}