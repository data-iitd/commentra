#include <stdio.h>

int main() {
	// Declaring a variable's' of type 'char' to store the input string
	char s[100000];

	// Reading the string input using'scanf' function
	scanf("%s", s);

	// Declaring a variable 'ans' of type 'int' to store the answer
	int ans = 0;

	// Looping through each character 'c' in the string's'
	for (int i = 0; s[i]!= '\0'; i++) {
		// Checking if the current character 'c' is equal to '1'
		if (s[i] == '1') {
			// Incrementing the answer if the character is '1'
			ans++;
		}
	}

	// Printing the answer using 'printf' function
	printf("%d", ans);

	// End of the code
}

