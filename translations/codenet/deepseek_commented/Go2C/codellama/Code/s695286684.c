#include <stdio.h>
#include <string.h>

int main() {
	char s[100];
	// Read a string from the standard input and store it in the variable 's'.
	scanf("%s", s);
	// Replace all occurrences of "2017" with "2018" in the string 's' and print the result.
	printf("%s\n", strstr(s, "2017"));
	return 0;
}

