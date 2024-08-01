#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) p = malloc(s)
#define TRUE 1
#define FALSE 0
#define MAX 20
#define COMPARE(a, b) (a == b) ? 0: (a < b) ? -1: 1

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
};

polyPointer createPolyNode_h(void);
void fprintList(polyPointer CL, FILE* fpo);
void insertNode(polyPointer* CL, int coef, int expon);
void Polynomials(FILE* fpi, FILE* fpo);

int main(void) {
	FILE *fpi,*fpo;
	fpi = fopen("input.txt", "r");
	fpo = fopen("output.txt", "w");
	Polynomials(fpi, fpo);
	fclose(fpi);
	fclose(fpo);
	return 0;
}

//NULL 원형 연결 리스트 생성
polyPointer createPolyNode_h(void) {
	polyPointer h;
	MALLOC(h, sizeof(*h));
	h = NULL;
	return h;
}

// 연결 리스트를 순서대로 출력
void fprintList(polyPointer CL, FILE* fpo) {
	polyPointer p;
	p = CL;
	do {
		fprintf(fpo, "%d\t%d", p->coef, p->expon);
		p = p->link;
		if (p != CL) fprintf(fpo, "\n");
	} while (p != CL);
}

// 첫 번째 노드 삽입 연산
void insertNode(polyPointer* CL, int coef, int expon) {
	polyPointer newNode, temp;
	MALLOC(newNode, sizeof(*newNode));	// 삽입할 새 노드 할당
	newNode->coef =  coef;				// 새 노드의 값 입력
	newNode->expon = expon;

	if (*CL == NULL) {
		*CL = newNode;					// 새 노드를 리스트의 시작 노드로 연결
		newNode->link = newNode;
	}
	else {								// 원형 연결 리스트가 공백이 아닌 경우 	
		temp = *CL;
		do {
			temp = temp->link;
		} while (temp->link != *CL);
		newNode->link = temp->link;
		temp->link = newNode;			// 마지막 노드를 첫 번째 노드인 new와 원형 연결 
		*CL = newNode;
	}
	*CL = (*CL)->link;					// 리스트의 시작 노드를 다음 노드로 변경
}

void Polynomials(FILE *fpi, FILE *fpo) {
	int n, m, i, buff_coef, buff_expon, sum, done = FALSE;
	polyPointer a, b, c, startA, lastC;
	a = createPolyNode_h();
	b = createPolyNode_h();
	c = createPolyNode_h();
	insertNode(&a, -1, -1);
	insertNode(&b, -1 ,-1);

	startA = a;
	lastC = c;

	fscanf(fpi, "%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		fscanf(fpi,"%d %d", &buff_coef, &buff_expon);
		insertNode(&a, buff_coef, buff_expon);
	}
	for (i = 0; i < m; i++) {
		fscanf(fpi,"%d %d", &buff_coef, &buff_expon);
		insertNode(&b, buff_coef, buff_expon);
	}

	a = a->link;
	b = b->link;

	do {
		switch (COMPARE(a->expon, b->expon)) {
		case -1:
			insertNode(&lastC, b->coef, b->expon);
			b = b->link;
			break;
		case 0:
			if (startA == a) done = TRUE;
			else {
				sum = a->coef + b->coef;
				if (sum) {
					insertNode(&lastC, sum, a->expon);
				}
				a = a->link; b = b->link;
			}
			break;
		case 1:
			insertNode(&lastC, a->coef, a->expon);
			a = a->link;
		}
	} while (!done);
	c = lastC;

	fprintList(c, fpo);
}