#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20

int main(void) {
	int i, len;
	char arr[3][MAX_SIZE];
	char(*ptr)[MAX_SIZE] = arr;
	char buff[MAX_SIZE] = { 0 };

	FILE* fpo, * fpi;

	fpi = fopen("input.txt", "r");
	fpo = fopen("output.txt", "w");

	i = 0;
	while (fgets(buff, MAX_SIZE, fpi) != NULL)
		strcpy(arr[i++], buff);

	len = i;

	for (i = 0; i < len; i++) 
		fputs(*(ptr + (i)), fpo);

	fclose(fpi);
	fclose(fpo);
	return 0;
}