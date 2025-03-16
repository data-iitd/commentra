
#include <stdio.h>
#include <string.h>

int main()
{
	// Declare two string variables, s and t
	char s[100], t[100];
	
	// Read a string from the standard input and store it in s
	scanf("%s", s);
	
	// Assign the first character of s to t
	t[0] = s[0];
	
	// Append the size of s minus 2 to t
	sprintf(t + 1, "%d", strlen(s) - 2);
	
	// Append the last character of s to t
	t[strlen(s) - 1] = s[strlen(s) - 1];
	
	// Print the modified string t
	puts(t);
	
	return 0;
}
