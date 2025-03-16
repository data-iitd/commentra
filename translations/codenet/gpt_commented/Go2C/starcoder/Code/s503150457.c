


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Declare three string variables to hold user input
	char s1[100], s2[100], s3[100];
	
	// Read three strings from standard input
	scanf("%s %s %s", s1, s2, s3);

	// Split each string into a slice of individual characters
	char *s1s[strlen(s1)];
	char *s2s[strlen(s2)];
	char *s3s[strlen(s3)];

	// Convert the first character of each string to uppercase and concatenate them
	char result[strlen(s1s[0]) + strlen(s2s[0]) + strlen(s3s[0])];
	strcpy(result, toupper(s1s[0]));
	strcat(result, toupper(s2s[0]));
	strcat(result, toupper(s3s[0]));
	
	// Print the concatenated result
	printf("%s", result);
}

