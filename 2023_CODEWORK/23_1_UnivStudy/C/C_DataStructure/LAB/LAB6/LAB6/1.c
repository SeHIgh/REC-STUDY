//infix expression -> post expression 변환 출력
//TUTOR) 출력 시  postfix 변환 + 계산한 값 둘다 출력할 것!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 50
#define FALSE 0
#define TRUE 1

int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };
typedef enum { lparen = 0, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

precedence getToken(char expr[], char* symbol, int* n);
char printToken(int token);
int IsEmpty(int top);
int IsFull(int top);
void push(int stack[], int* top, int value);
int pop(int stack[], int* top);

void postfix(char inf_arr[], char postf_arr[], FILE* fpc);
int Evaluate_postfix(char postf_arr[], FILE* fpc);

int main(void) {
	char inf_arr[MAX_SIZE] = { 0 }, postf_arr[MAX_SIZE] = { 0 };
	int result;
	FILE* fpo, * fpc;
	fpo = fopen("input.txt", "r");
	fpc = fopen("output.txt", "w");
	int i = 0, len;
	while (fscanf(fpo, "%c ", &inf_arr[i++]) != EOF) {}
	len = i - 1;
	postfix(inf_arr, postf_arr, fpc);
	result = Evaluate_postfix(postf_arr, fpc);
	fprintf(fpc, "%d", result);
	fclose(fpo);
	fclose(fpc);
	return 0;
}

precedence getToken(char expr[], char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen; break;
	case ')': return rparen; break;
	case '+': return plus; break;
	case '-': return minus; break;
	case '*': return times; break;
	case '/': return divide; break;
	case '%': return mod; break;
	case NULL: return eos; break;	// ' '를 인식을 못함
	default: return operand;
	}
}

char printToken(int token) {
	switch (token) {
	case lparen: return '('; break;
	case rparen: return ')'; break;
	case plus: return '+'; break;
	case minus: return '-'; break;
	case times: return '*'; break;
	case divide: return '/'; break;
	case mod: return '%'; break;
	case eos: return NULL; break;
	}
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

void postfix(char inf_arr[], char postf_arr[], FILE* fpc) {
	char symbol, temp;
	int stack[MAX_SIZE] = { 0 };
	precedence token;
	int j, n = 0, top = 0;
	stack[0] = eos;
	j = -1;
	for (token = getToken(inf_arr, &symbol, &n); token != eos; token = getToken(inf_arr, &symbol, &n)) {
		if (token == operand) {
			fprintf(fpc, "%c ", symbol);
			postf_arr[++j] = symbol;
		}
		else if (token == rparen) {
			while (stack[top] != lparen) {
				temp = printToken(pop(stack, &top));
				fprintf(fpc, "%c ", temp);
				postf_arr[++j] = temp;
			}
			pop(stack, &top);
		}
		else {
			while (isp[stack[top]] >= icp[token]) {
				temp = printToken(pop(stack, &top));
				fprintf(fpc, "%c ", temp);
				postf_arr[++j] = temp;
			}
			push(stack, &top, token);
		}
	}
	while ((token = pop(stack, &top)) != eos) {
		temp = printToken(token);
		fprintf(fpc, "%c ", temp);
		postf_arr[++j] = temp;
	}
	fprintf(fpc, "\n");
}

int Evaluate_postfix(char postf_arr[], FILE* fpc) {
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	int stack[MAX_SIZE] = { 0 };
	token = getToken(postf_arr, &symbol, &n);
	while (token != eos) {
		if (token == operand)
			push(stack, &top, symbol - '0');
		else {
			op2 = pop(stack, &top);
			op1 = pop(stack, &top);
			switch (token)
			{
			case plus: push(stack, &top, op1 + op2); break;
			case minus: push(stack, &top, op1 - op2); break;
			case times: push(stack, &top, op1 * op2); break;
			case divide: push(stack, &top, op1 / op2); break;
			case mod: push(stack, &top, op1 % op2); break;
			}
		}
		token = getToken(postf_arr, &symbol, &n);
	}
	return pop(stack, &top);
}