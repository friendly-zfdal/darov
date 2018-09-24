#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void add(void*a, const void* b) {
	*(int*)a += *((int*)b);
}

void add1(void*a, const void* b) {
	*(int*)a += (int)(*(char*)b);
}

void universalSum(void* base, int num, int size, void* init, void(*add)(void*, const void*)) {

	for (int i = 0; i < num; i++) {
		add(init, (char*)base + i*size);
}




	return NULL;
}


int main() {
	int size;
	scanf("%d ", &size);
	char* arr = malloc(20 * sizeof(char));
	int* arr1 = malloc(20 * sizeof(int));

	int sum=0;
	if (size == 1) {
		for (int i = 0; i < 20; i++) 
			scanf("%c ", arr + i);

		universalSum(arr, 20, size, &sum, add1);
	}
	if (size == 4) {
		for (int i = 0; i < 20; i++)
			scanf("%d ", arr1 + i);
		universalSum(arr1, 20, size, &sum, add);
	}
	printf("%d", sum);





	return 0;
}