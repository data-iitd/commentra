#include <stdio.h>

char* group(int n) { // Function to determine group based on input number n
	if (n == 4 || n == 6 || n == 9 || n == 11) { // Check if number belongs to group B
		return "B";
	} else {
		return "A";
	}
}

int main() { // Main function
	int x, y; // Declare variables x and y of type int
	scanf("%d %d", &x, &y); // Read input values of x and y from standard input

	if (x == 2 || y == 2) { // Check if either x or y is equal to 2
		printf("No\n"); // If yes, print "No" and exit
		return 0;
	}

	char* xg = group(x); // Determine group of number x
	char* yg = group(y); // Determine group of number y

	if (xg == yg) { // Check if both numbers belong to the same group
		printf("Yes\n"); // If yes, print "Yes"
	} else {
		printf("No\n"); // If not, print "No"
	}

	return 0;
}

