#include <stdio.h>  // Include the standard input-output library

int main(void) {   // Define the main function, the entry point of the program
	int h, r;      // Declare two integer variables
	scanf("%d%d", &h, &r);  // Read two integers from the standard input and store them in h and r
	if (r > -h) {  // Check if r is greater than -h
		printf("1\n");  // If true, print 1
	} else if (r == -h) {  // If the condition in the if statement is false, check if r is equal to -h
		printf("0\n");  // If true, print 0
	} else {  // If neither of the above conditions is true
		printf("-1\n");  // Print -1
	}
	return 0;  // Return 0, indicating successful execution
}
