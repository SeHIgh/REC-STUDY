#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 30
void strlwrupr(char* input);
int main(int argc, char* argv[]) {
	FILE* fp1, * fp2;
	char temp[MAX_SIZE];
	fp1 = fopen(argv[1], "r+");
	fp2 = fopen("output.txt", "w");
	while (fgets(temp, MAX_SIZE, fp1) != NULL) {
		strlwrupr(temp);
		fputs(temp, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
void strlwrupr(char* input) {
	int i;
	for (i = 0; i < strlen(input); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z')
			input[i] += (-'A' + 'a');
		else if (input[i] >= 'a' && input[i] <= 'z')
			input[i] += (-'a' + 'A');
	}
}