#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Book {
	char name[30];
	char author[30];
	unsigned int pages;
	char isbn[20];
};

int cmp(const void* a, const void* b) {
	if (strcmp(((struct Book*)a)->name, ((struct Book*)b)->name) == 0) {
		if (strcmp(((struct Book*)a)->author, ((struct Book*)b)->author) == 0) {
			return ((struct Book*)a)->pages - ((struct Book*)b)->pages;



		}
		else if (strcmp(((struct Book*)a)->author, ((struct Book*)b)->author) > 0)
			return -1;
		else if (strcmp(((struct Book*)a)->author, ((struct Book*)b)->author) < 0)
			return 1;
	}
	if (strcmp(((struct Book*)a)->name, ((struct Book*)b)->name) < 0)
		return 1;
	if (strcmp(((struct Book*)a)->name, ((struct Book*)b)->name) > 0)
		return -1;




}

int main() {
	int num;
	scanf("%d\n", &num);
	struct Book* arr=malloc(num*sizeof(struct Book));
	for (int i = 0; i < num; i++) {
		scanf("%s ", (arr+i)->name);
		scanf("%s ", (arr + i)->author);
		scanf("%d ", &((arr + i)->pages));
		scanf("%s", (arr + i)->isbn);
	}
	qsort(arr, num, sizeof(struct Book), cmp);
	for (int i = 0; i < num; i++) {
		printf("%s %s %d %s ", (arr + i)->name, (arr + i)->author, (arr + i)->pages, (arr + i)->isbn);
	}
	return 0;
}