#include <stdio.h>
#include <string.h>

int main() {
	// Declare a string variable to store user input
	char s[100];
	
	// Read a string input from the user and store it in `s`
	scanf("%s", s);
	
	// Check if the length of `s` is at least 4 and if the first four characters are "YAKI"
	if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
		// If the condition is true, print "Yes"
		printf("Yes\n");
	} else {
		// Otherwise, print "No"
		printf("No\n");
	}
	
	// End of code
	return 0;
}