#include<stdio.h>  // Step 1: Include the standard input/output library.

// Step 2: Define a function named 'swap' that takes two integer pointers as arguments.
void swap(int *a, int *b) {
	int tmp;  // Step 3: Inside the 'swap' function, declare a temporary variable 'tmp'.
	tmp = *a;  // Step 4: Assign the value pointed to by 'a' to 'tmp'.
	*a = *b;  // Step 5: Assign the value pointed to by 'b' to the memory location pointed to by 'a'.
	*b = tmp;  // Step 6: Assign the value stored in 'tmp' to the memory location pointed to by 'b'.
}

int main() {  // Step 7: In the 'main' function, declare two integer variables 'a' and 'b'.
	while(1) {  // Step 8: Create an infinite loop using 'while(1)'.
		int a, b;
		scanf("%d %d", &a, &b);  // Step 9: Use 'scanf' to read two integers from the user and store them in 'a' and 'b'.
		if (a == 0 && b == 0) break;  // Step 10: Check if both 'a' and 'b' are zero. If true, break the loop.
		if (b < a) swap(&a, &b);  // Step 11: Check if 'b' is less than 'a'. If true, call the 'swap' function to swap the values of 'a' and 'b'.
		printf("%d %d\n", a, b);  // Step 12: Print the values of 'a' and 'b'.
	}
	return 0;  // Step 13: End the 'main' function with 'return 0'.
}
