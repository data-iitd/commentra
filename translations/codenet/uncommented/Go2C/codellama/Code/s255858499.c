#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[100], b[100];
	scanf("%s", a);
	scanf("%s", b);
	int a_int = atoi(a);
	int b_int = atoi(b);

	if (a_int * b_int % 2 != 0) {
		printf("Odd\n");
	} else {
		printf("Even\n");
	}
	return 0;
}
