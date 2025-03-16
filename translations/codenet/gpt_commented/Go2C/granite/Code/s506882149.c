
#include <stdio.h> // Include the stdio.h header file for formatted I/O operations

// comp function compares two integers x and a.
// It returns 0 if x is less than a, otherwise it returns 10.
int comp(int x, int a) {
	// Check if x is less than a
	if (x < a) {
		return 0; // Return 0 if the condition is true
	} 
	return 10; // Return 10 if x is not less than a
}

int main() {
	int x, a; // Declare two integer variables x and a
	// Read input values for x and a from the user
	scanf("%d %d", &x, &a);
	
	// Call the comp function with x and a, and print the result
	printf("%d\n", comp(x, a));
	
	return 0; // Return 0 to indicate successful execution
}
