
#include<stdio.h> // Include the standard C library for input/output operations
#include<stdbool.h> // Include the standard boolean library for boolean data type
#include<stdlib.h> // Include the standard library for memory allocation and deallocation
#include<string.h> // Include the standard string library for string manipulation

int main() {
	int n; // Declare an integer variable to store the number of operations
	char str[10], com[13]; // Declare character arrays to store commands and strings
	bool *T; // Declare a pointer to a boolean variable to store the presence of strings
	T = (bool*)malloc(sizeof(bool)); // Allocate memory for the boolean variable

	scanf("%d", &n); // Read the number of operations from the user
	for (int i = 0; i < n; i++) { // Loop through each operation
		scanf("%s%s", com, str); // Read the command and the string
		if (com[0] == 'i') *T = true; // If the command is 'i', set the boolean variable to true
		else { // If the command is not 'i'
			if (*T) printf("yes\n"); // Check if the boolean variable is true and print 'yes'
			else printf("no\n"); // If the boolean variable is false, print 'no'
		}
	}
	free(T); // Deallocate the memory for the boolean variable
	return 0; // Return 0 to indicate successful execution
}
