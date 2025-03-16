#include <stdio.h>
#include <string.h>

int main() {
	// Declare three string variables to hold user input
	char s1[100], s2[100], s3[100];
	
	// Read three strings from standard input
	scanf("%s %s %s", s1, s2, s3);

	// Split each string into a slice of individual characters
	char s1s[100], s2s[100], s3s[100];
	strcpy(s1s, s1);
	strcpy(s2s, s2);
	strcpy(s3s, s3);

	// Convert the first character of each string to uppercase and concatenate them
	char result[100];
	result[0] = toupper(s1s[0]);
	result[1] = toupper(s2s[0]);
	result[2] = toupper(s3s[0]);
	result[3] = '\0';
	
	// Print the concatenated result
	printf("%s\n", result);
	
	return 0;
}

