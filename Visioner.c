#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char* str=malloc(60*sizeof(char));
	char* key=malloc(20*sizeof(char));
	scanf("%s ", str);
	scanf("%s", key);
	int n = strlen(key);
	int m = strlen(str);
	int a = 97;
	for (int i = 0; i < m; i++){
		
		printf("%c",97+((*(str+i)+26-*(key+i%n))%26));
		
	}



	return 0;
}