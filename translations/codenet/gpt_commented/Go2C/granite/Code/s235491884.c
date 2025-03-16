
#include <stdio.h>
#include <string.h>

int main() {
	char s[100]; // Declare a character array's' to hold the input string
	scanf("%s", s); // Read a string from standard input and store it in's'

	// Count the occurrences of the letter 'o' in the input string's'
	int n = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == 'o') {
			n++;
		}
	}

	// Calculate the result based on the count of 'o' and print it
	// The formula adds 700 to 100 times the count of 'o'
	printf("%d\n", 700 + n*100);
}

