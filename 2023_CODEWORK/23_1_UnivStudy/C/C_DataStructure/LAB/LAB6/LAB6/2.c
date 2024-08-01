////infix expression -> post expression 변환 출력
//// 단, 연산자 +, -, /, *, % 에서 &&, ||, ==, !=, <, >, <= , >= 추가로 수행 
////TUTOR) 출력 시  postfix 변환 + 계산한 값 둘다 출력할 것!
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#define MAX_SIZE 50
//#define FALSE 0
//#define TRUE 1
//
//int isp[] = { 0,19,12,12,13,13,13,4,5,9,9,10,10,10,10,0 };
//int icp[] = { 20,19,12,12,13,13,13,4,5,9,9,10,10,10,10,0 };
//typedef enum { lparen = 0, rparen, plus, minus, times, divide, mod, or, and, equal, nonequal, less, greater, les_equal, gre_equal, eos, operand } precedence;
//
//precedence getToken(char expr[], char* symbol, int* n);
//char* printToken(int token);
//int IsEmpty(int top);
//int IsFull(int top);
//void push(int stack[], int* top, int value);
//int pop(int stack[], int* top);
//
//void postfix(char inf_arr[], char postf_arr[], FILE* fpc);
//int Evaluate_postfix(char postf_arr[], FILE* fpc);
//
//int main(void) {
//	char inf_arr[MAX_SIZE] = { 0 }, postf_arr[MAX_SIZE] = { 0 };
//	int result;
//	FILE* fpo, * fpc;
//	fpo = fopen("input.txt", "r");
//	fpc = fopen("output.txt", "w");
//	int i = 0, len;
//	while (fscanf(fpo, "%c ", &inf_arr[i++]) != EOF) {}
//	len = i - 1;
//	postfix(inf_arr, postf_arr, fpc);
//	result = Evaluate_postfix(postf_arr, fpc);
//	fprintf(fpc, "%d", result);
//	fclose(fpo);
//	fclose(fpc);
//	return 0;
//}
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
//int IsEmpty(int top) {
//	if (top < 0)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//int IsFull(int top) {
//	if (top >= MAX_SIZE - 1)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//void push(int stack[], int* top, int value) {
//	if (IsFull(*top) == FALSE) {
//		stack[++(*top)] = value;
//	}
//}
//
//int pop(int stack[], int* top) {
//	if (IsEmpty(*top) == FALSE)
//		return stack[(*top)--];
//}
//
//void postfix(char inf_arr[], char postf_arr[], FILE* fpc) {
//	char symbol, temp[MAX_SIZE];
//	int stack[MAX_SIZE] = { 0 };
//	precedence token;
//	int j, n = 0, top = 0;
//	stack[0] = eos;
//	j = -1;
//	for (token = getToken(inf_arr, &symbol, &n); token != eos; token = getToken(inf_arr, &symbol, &n)) {
//		if (token == operand) {
//			sprintf(temp, "%c", symbol); //symbol은 문자이기 때문에 문자열로 변환
//			fprintf(fpc, "%s ", temp);
//			strcat(postf_arr, temp);
//		}
//		else if (token == rparen) {
//			while (stack[top] != lparen) {
//				strcpy(temp, printToken(pop(stack, &top)));
//				fprintf(fpc, "%s ", temp);
//				strcat(postf_arr, temp);
//			}
//			pop(stack, &top);
//		}
//		else {
//			while (isp[stack[top]] >= icp[token]) {
//				strcpy(temp, printToken(pop(stack, &top)));
//				fprintf(fpc, "%s ", temp);
//				strcat(postf_arr, temp);
//			}
//			push(stack, &top, token);
//		}
//	}
//	while ((token = pop(stack, &top)) != eos) {
//		strcpy(temp, printToken(token));
//		fprintf(fpc, "%s ", temp);
//		strcat(postf_arr, temp);
//	}
//	fprintf(fpc, "\n");
//}
//
//int Evaluate_postfix(char postf_arr[], FILE* fpc) {
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int n = 0;
//	int top = -1;
//	int stack[MAX_SIZE] = { 0 };
//	token = getToken(postf_arr, &symbol, &n);
//	while (token != eos) {
//		if (token == operand)
//			push(stack, &top, symbol - '0');
//		else {
//			op2 = pop(stack, &top);
//			op1 = pop(stack, &top);
//			switch (token)
//			{
//			case plus: push(stack, &top, op1 + op2); break;
//			case minus: push(stack, &top, op1 - op2); break;
//			case times: push(stack, &top, op1 * op2); break;
//			case divide: push(stack, &top, op1 / op2); break;
//			case mod: push(stack, &top, op1 % op2); break;
//			case or: push(stack, &top, op1 || op2); break;
//			case and: push(stack, &top, op1 && op2); break;
//			case equal: push(stack, &top, op1 == op2); break;
//			case nonequal: push(stack, &top, op1 != op2); break;
//			case less: push(stack, &top, op1 < op2); break;
//			case greater: push(stack, &top, op1 > op2); break;
//			case les_equal: push(stack, &top, op1 <= op2); break;
//			case gre_equal: push(stack, &top, op1 >= op2); break;
//			}
//		}
//		token = getToken(postf_arr, &symbol, &n);
//	}
//	return pop(stack, &top);
//}