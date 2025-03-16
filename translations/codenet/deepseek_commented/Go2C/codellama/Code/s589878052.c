#include <stdio.h>

int main() {
	int a, b, h; // Declaring three integer variables a, b, and h
	scanf("%d %d %d", &a, &b, &h); // Reading three integers from the standard input and storing them in a, b, and h

	printf("%d\n", (a + b) * h / 2); // Calculating and printing the area of a trapezoid

	return 0;
}
