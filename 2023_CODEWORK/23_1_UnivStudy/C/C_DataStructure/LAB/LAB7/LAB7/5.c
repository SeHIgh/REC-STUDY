//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define IS_EMPTY(first) (!(first))
//#define MALLOC(p, s) p = malloc(s)
//#define MAX_SIZE 50
//#define FALSE 0
//#define TRUE 1
//
////linked list 구조체 지정
//typedef struct listNode* listPointer;
//typedef struct listNode {
//	int data;
//	listPointer link;
//};
//typedef struct {
//	listPointer top;
//}linkedStack;
//
//int isp[] = { 0,19,12,12,13,13,13,4,5,9,9,10,10,10,10,0 };
//int icp[] = { 20,19,12,12,13,13,13,4,5,9,9,10,10,10,10,0 };
//typedef enum { lparen = 0, rparen, plus, minus, times, divide, mod, or, and, equal, nonequal, less, greater, les_equal, gre_equal, eos, operand } precedence;
//
//void init(linkedStack* stack);
//int IsEmpty(linkedStack* stack);
//int IsFull(linkedStack* stack);
//void push(linkedStack* stack, int value);
//int pop(linkedStack* stack);
//
//precedence getToken(char expr[], char* symbol, int* n);
//char* printToken(int token);
//void postfix(char inf_arr[], char postf_arr[], FILE* fpc);
//int Evaluate_postfix(char postf_arr[], FILE* fpc);
//
//int main(void) {
//	char inf_arr[MAX_SIZE] = { 0 }, postf_arr[MAX_SIZE] = { 0 };
//	int result;
//	FILE* fpi, * fpo;
//	fpi = fopen("input.txt", "r");
//	fpo = fopen("output.txt", "w");
//	int i = 0, len;
//	while (fscanf(fpi, "%c ", &inf_arr[i++]) != EOF) {}
//	len = i - 1;
//	postfix(inf_arr, postf_arr, fpo);
//	result = Evaluate_postfix(postf_arr, fpo);
//	fprintf(fpo, "%d", result);
//	fclose(fpi);
//	fclose(fpo);
//	return 0;
//}
//
//void init(linkedStack* stack) {
//	stack->top = NULL;
//}
//
//int IsEmpty(linkedStack* stack) {
//	return(stack->top = NULL);
//}
//
//int IsFull(linkedStack* stack) {
//	return 0;
//}
//
//void push(linkedStack* stack, int value) {
//	listPointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->data = value;
//	temp->link = stack->top;
//	stack->top = temp;
//}
//
//int pop(linkedStack* stack) {
//		listPointer temp = stack->top;
//		int data = temp->data;
//		stack->top = stack->top->link;
//		free(temp);
//		return data;
//}
//
////연속된 두 문자를 받아들이기가 관건
//precedence getToken(char expr[], char* symbol, int* n) {
//	*symbol = expr[(*n)++];
//	switch (*symbol) {
//	case '(': return lparen; break;
//	case ')': return rparen; break;
//	case '+': return plus; break;
//	case '-': return minus; break;
//	case '*': return times; break;
//	case '/': return divide; break;
//	case '%': return mod; break;
//	case '|': 
//		if (expr[(*n)++] == '|') {			//중복 입력 및 연속된 문자의 case판단을 위해 문자를 받아들이고 ++을 해줘 다음 루프에서 그냥 넘겨버리기
//			return or ;
//			break;
//		}
//	case '&': 
//		if (expr[(*n)++] == '&') {
//			return and ;
//			break;
//		}
//	case '=': 
//		if (expr[(*n)++] == '=') {
//			return equal;
//			break;
//		}
//	case '!':
//		if (expr[(*n)++] == '=') {
//			return nonequal;
//			break;
//		}
//	case '<': 
//		if (expr[(*n)++] == '=') {
//			return les_equal;
//			break;
//		}
//		else {
//			return equal;
//			break;
//		}
//	case '>':
//		if (expr[(*n)++] == '=') {
//			return gre_equal;
//			break;
//		}
//		else {
//			return greater;
//			break;
//		}
//	case NULL: return eos; break;	// ' '를 인식을 못함
//	default: return operand;
//	}
//}
//
//char* printToken(int token) {
//	switch (token) {
//	case lparen: return "("; break;
//	case rparen: return ")"; break;
//	case plus: return "+"; break;
//	case minus: return "-"; break;
//	case times: return "*"; break;
//	case divide: return "/"; break;
//	case mod: return "%"; break;
//	case or : return "||"; break;
//	case and : return "&&"; break;
//	case equal: return "=="; break;
//	case nonequal: return "!="; break;
//	case less: return "<"; break;
//	case greater: return ">"; break;
//	case les_equal: return "<="; break;
//	case gre_equal: return ">="; break;
//	case eos: return NULL; break;
//	}
//}
//
//void postfix(char inf_arr[], char postf_arr[], FILE* fpo) {
//	char symbol, temp[MAX_SIZE];
//	linkedStack stack;
//	init(&stack);
//	precedence token;
//	int j, n = 0;
//	push(&stack, eos);
//	j = -1;
//	for (token = getToken(inf_arr, &symbol, &n); token != eos; token = getToken(inf_arr, &symbol, &n)) {
//		if (token == operand) {
//			sprintf(temp, "%c", symbol); //symbol은 문자이기 때문에 문자열로 변환
//			fprintf(fpo, "%s ", temp);
//			strcat(postf_arr, temp);
//		}
//		else if (token == rparen) {
//			while (stack.top->data != lparen) {
//				strcpy(temp, printToken(pop(&stack)));
//				fprintf(fpo, "%s ", temp);
//				strcat(postf_arr, temp);
//			}
//			pop(&stack);
//		}
//		else {
//			while (isp[stack.top->data] >= icp[token]) {
//				strcpy(temp, printToken(pop(&stack)));
//				fprintf(fpo, "%s ", temp);
//				strcat(postf_arr, temp);
//			}
//			push(&stack, token);
//		}
//	}
//	while ((token = pop(&stack)) != eos) {
//		strcpy(temp, printToken(token));
//		fprintf(fpo, "%s ", temp);
//		strcat(postf_arr, temp);
//	}
//	fprintf(fpo, "\n");
//}
//
//int Evaluate_postfix(char postf_arr[], FILE* fpo) {
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int n = 0;
//	int top = -1;
//	linkedStack stack;
//	init(&stack);
//	token = getToken(postf_arr, &symbol, &n);
//	while (token != eos) {
//		if (token == operand)
//			push(&stack, symbol - '0');
//		else {
//			op2 = pop(&stack);
//			op1 = pop(&stack);
//			switch (token)
//			{
//			case plus: push(&stack, op1 + op2); break;
//			case minus: push(&stack, op1 - op2); break;
//			case times: push(&stack, op1 * op2); break;
//			case divide: push(&stack, op1 / op2); break;
//			case mod: push(&stack, op1 % op2); break;
//			case or: push(&stack, op1 || op2); break;
//			case and: push(&stack, op1 && op2); break;
//			case equal: push(&stack, op1 == op2); break;
//			case nonequal: push(&stack, op1 != op2); break;
//			case less: push(&stack, op1 < op2); break;
//			case greater: push(&stack, op1 > op2); break;
//			case les_equal: push(&stack, op1 <= op2); break;
//			case gre_equal: push(&stack, op1 >= op2); break;
//			}
//		}
//		token = getToken(postf_arr, &symbol, &n);
//	}
//	return pop(&stack);
//}