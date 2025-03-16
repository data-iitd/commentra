#include <stdio.h>

int comp(int x, int a) {
	if (x < a) {
		return 0;
	}
	return 10;
}

int main() {
	int x, a;
	scanf("%d %d", &x, &a);
	
	printf("%d\n", comp(x, a));
	
	return 0;
}

