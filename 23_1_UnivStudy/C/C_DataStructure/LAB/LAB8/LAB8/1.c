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

//NULL ���� ���� ����Ʈ ����
polyPointer createPolyNode_h(void) {
	polyPointer h;
	MALLOC(h, sizeof(*h));
	h = NULL;
	return h;
}

// ���� ����Ʈ�� ������� ���
void fprintList(polyPointer CL, FILE* fpo) {
	polyPointer p;
	p = CL;
	do {
		fprintf(fpo, "%d\t%d", p->coef, p->expon);
		p = p->link;
		if (p != CL) fprintf(fpo, "\n");
	} while (p != CL);
}

// ù ��° ��� ���� ����
void insertNode(polyPointer* CL, int coef, int expon) {
	polyPointer newNode, temp;
	MALLOC(newNode, sizeof(*newNode));	// ������ �� ��� �Ҵ�
	newNode->coef =  coef;				// �� ����� �� �Է�
	newNode->expon = expon;

	if (*CL == NULL) {
		*CL = newNode;					// �� ��带 ����Ʈ�� ���� ���� ����
		newNode->link = newNode;
	}
	else {								// ���� ���� ����Ʈ�� ������ �ƴ� ��� 	
		temp = *CL;
		do {
			temp = temp->link;
		} while (temp->link != *CL);
		newNode->link = temp->link;
		temp->link = newNode;			// ������ ��带 ù ��° ����� new�� ���� ���� 
		*CL = newNode;
	}
	*CL = (*CL)->link;					// ����Ʈ�� ���� ��带 ���� ���� ����
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