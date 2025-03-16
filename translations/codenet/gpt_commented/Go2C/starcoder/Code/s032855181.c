


#include <stdio.h>
#include <stdlib.h>

// group function determines the group classification based on the input number n.
// It returns "B" for specific values (4, 6, 9, 11) and "A" for all other values.
char* group(int n) {
	if (n == 4 || n == 6 || n == 9 || n == 11) {
		return "B";
	} else {
		return "A";
	}
}

int main() {
	// Declare variables to hold the input values for x and y
	int x, y;

	// Read two integers from standard input
	scanf("%d %d", &x, &y);

	// Check if either x or y is equal to 2, and print "No" if true
	// This is based on the problem's specific condition
	if (x == 2 || y == 2) {
		printf("No\n");
		return 0; // Exit the function early if the condition is met
	}

	// Determine the group classification for both x and y
	char* xg = group(x);
	char* yg = group(y);

	// Compare the group classifications of x and y
	// Print "Yes" if they belong to the same group, otherwise print "No"
	if (strcmp(xg, yg) == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

