#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 20
#define MALLOC(p, s) p = malloc(s)

typedef int Data;
typedef struct _node {
	Data data;
	struct _node *next;
}Node;

void EquivalenceClasses(FILE* fpi, FILE* fpo);

int main(void) {
	FILE* fpi, * fpo;
	fpi = fopen("input.txt", "r");
	fpo = fopen("output.txt", "w");

	EquivalenceClasses(fpi, fpo);

	fclose(fpi);
	fclose(fpo);
	return 0;
}

void EquivalenceClasses(FILE* fpi, FILE* fpo) {
	short int out[MAX_SIZE];
	int storage[MAX_SIZE][MAX_SIZE] = { 0 };
	Node* seq[MAX_SIZE];
	Node* x, * y, * top;
	int i, j, k, n, setcnt = 0, elecnt = 0;

	fscanf(fpi, "%d", &n);
	for (i = 0; i < MAX_SIZE; i++) {
		out[i] = TRUE; seq[i] = NULL;
	}
	//Phase 1: input pairs
	for (k = 0; k < n; k++) {
		fscanf(fpi, "%d = %d", &i, &j);
		MALLOC(x, sizeof(*x));
		x->data = j; x->next = seq[i]; seq[i] = x;
		MALLOC(x, sizeof(*x));
		x->data = i; x->next = seq[j]; seq[j] = x;
	}
	//Phase 2: output classes
	for (i = 0; i < MAX_SIZE; i++) {
		//입력 안받은 값은 걸러야됨.
		if (seq[i] == NULL)
			continue;
		elecnt = 0;
		if (out[i]) {
			out[i] = FALSE;
			storage[setcnt][elecnt] = i;
			x = seq[i]; top = NULL;
			for (;;) {
				while (x) {
					j = x->data;
					if (out[j]) {
						out[j] = FALSE;
						storage[setcnt][++elecnt] = j;
						y = x->next; x->next = top; top = x; x = y;
					}
					else {
						x = x->next;
						break;
					}
				}
				if (!top) {
					setcnt++;
					break;
				}
				x = seq[top->data]; top = top->next;
			}
		}
	}
	fprintf(fpo, "%d\n", setcnt);
	for (i = 0; i < setcnt; i++) {
		j = 0;
		fprintf(fpo, "{");
		while (1) {
			if (storage[i][j + 1] != NULL) fprintf(fpo, "%d, ", storage[i][j++]);
			else {
				fprintf(fpo, "%d}", storage[i][j++]);
				break;
			}
		}
		if (i < setcnt - 1)
			fprintf(fpo, ", ");
	}
}