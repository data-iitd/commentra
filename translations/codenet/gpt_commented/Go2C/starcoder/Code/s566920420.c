


#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	
	// Calculate the expression a + a^2 + a^3 and print the result
	printf("%d\n", a + a*a + a*a*a);
}

