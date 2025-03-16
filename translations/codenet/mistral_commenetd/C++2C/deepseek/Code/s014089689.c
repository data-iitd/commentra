#include <stdio.h> // Include the stdio library for input and output operations

int main(){ // Beginning of the main function
	int n; // Declare an integer variable 'n' to store the size of the string
	scanf("%d", &n); // Read the size of the string from the standard input
	char s[n+1]; // Declare a character array 's' to store the string with a size of n+1
	scanf("%s", s); // Read the string from the standard input
	int cnt=0; // Initialize a counter variable 'cnt' to 0

	// Beginning of the first for loop
	for(int i=0;i<n;i++){ // Loop through each character in the string 's'
		cnt++; // Increment the counter variable 'cnt'
		int j=i+1; // Initialize a variable 'j' to check for the next character

		// Beginning of the inner for loop
		for(;j<n;j++){ // Compare the current character with the next characters in the string
			if(s[i]!=s[j]){ // If the current character is not equal to the next character
				break; // Exit the inner for loop
			}
		}
		i=j-1; // If the current character is repeated, update the index 'i' to the previous index
	}

	// Output the result
	printf("%d\n", cnt); // Print the value of the counter variable 'cnt' to the standard output
}

