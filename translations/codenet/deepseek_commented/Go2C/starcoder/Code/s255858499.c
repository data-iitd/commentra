#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if(a*b%2!=0) {
		printf("Odd");
	} else {
		printf("Even");
	}
	return 0;
}
