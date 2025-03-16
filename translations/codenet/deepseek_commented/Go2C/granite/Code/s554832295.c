

#include <stdio.h>

int main() {
	// Declare variables to store the coordinates
	int x1, y1, x2, y2;
	
	// Read four integers from standard input
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	// Calculate the differences between the coordinates
	int a = x2 - x1;
	int b = y2 - y1;
	
	// Calculate the new coordinates based on the differences
	int x3 = x2 - b;
	int y3 = y2 + a;
	int x4 = x1 - b;
	int y4 = y1 + a;
	
	// Print the new coordinates to standard output
	printf("%d %d %d %d\n", x3, y3, x4, y4);
	
	return 0;
}
