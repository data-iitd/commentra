#include <stdio.h>
#include <string.h>

int main() {
	// Declare a string variable to hold user input
	char a[100];
	
	// Read input from the user and store it in `a`
	scanf("%s", a);
	
	// Replace all occurrences of "1" with "0" in the string `a`
	char tmp[100];
	strcpy(tmp, a);
	strcpy(tmp, str_replace(tmp, "1", "0"));
	
	// Store the result of the first replacement in a temporary variable `tmp`
	// Replace all occurrences of "9" with "1" in the string `tmp`
	char b[100];
	strcpy(b, tmp);
	strcpy(b, str_replace(b, "9", "1"));
	
	// Store the result of the second replacement in the variable `b`
	// Replace all occurrences of "0" with "9" in the string `b`
	char ans[100];
	strcpy(ans, b);
	strcpy(ans, str_replace(ans, "0", "9"));
	
	// Print the final result to the console
	printf("%s\n", ans);
	
	return 0;
}

char *str_replace(char *str, char *orig, char *rep) {
	static char buffer[100];
	char *p;
	
	if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
		return str;
	
	strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st
	buffer[p-str] = '\0';
	
	sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));
	
	return buffer;
}

