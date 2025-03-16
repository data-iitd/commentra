#include <stdio.h>
#include <string.h>

int main() {
	// Initialize a string variable to store the input
	char s[100000];
	// Read input from the standard input and store it in the variable `s`
	scanf("%s", s);
	
	// Initialize a variable to count the number of '1's in the input string
	int ans = 0;
	// Iterate over each character in the string `s`
	for (int i = 0; i < strlen(s); i++) {
		// Check if the character is '1'
		if (s[i] == '1') {
			// Increment the count of '1's
			ans++;
		}
	}
	// Print the count of '1's to the standard output
	printf("%d", ans);
}

