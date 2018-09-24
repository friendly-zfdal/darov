#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char* str = malloc(100 * sizeof(char));
	scanf("%s", str);
	printf("%d", strlen(str));
	for (int i = 0; i < strlen(str); i++)
		if (i % 2 == 0)
			printf("%c", *(str + i));
	for (int i = 0; i < strlen(str); i++)
		if (i % 2 != 0)
			printf("%c", *(str + i));

	return 0;
}