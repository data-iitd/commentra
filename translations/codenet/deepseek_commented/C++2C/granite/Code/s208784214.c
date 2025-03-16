
#include <stdio.h>

int main() {
	int N, A;
	scanf("%d %d", &N, &A);
	printf("%s\n", N % 500 <= A? "Yes" : "No");
	return 0;
}
