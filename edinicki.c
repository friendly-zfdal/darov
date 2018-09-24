#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int one() {
	int n;
	scanf("%d", &n);
	if (n == 0) {
		scanf("%d", &n);
		if (n == 0)
			return 0;
	}
		if (n == 1)
			return one() + 1;
			return one();
}
	

int main() {
	int m = one();
	printf("%d",m)
	return 0;
}