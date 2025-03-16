#include <stdio.h>
#include <string.h>

int main() {
	// Declare a string variable to hold user input
	char a[1000];
	
	// Read input from the user and store it in `a`
	scanf("%s", a);
	
	// Replace all occurrences of "1" with "0" in the string `a`
	char tmp[1000];
	strcpy(tmp, a);
	strreplace(tmp, "1", "0");
	
	// Store the result of the first replacement in a temporary variable `tmp`
	// Replace all occurrences of "9" with "1" in the string `tmp`
	char b[1000];
	strcpy(b, tmp);
	strreplace(b, "9", "1");
	
	// Store the result of the second replacement in the variable `b`
	// Replace all occurrences of "0" with "9" in the string `b`
	char ans[1000];
	strcpy(ans, b);
	strreplace(ans, "0", "9");
	
	// Print the final result to the console
	printf("%s", ans);
}

void strreplace(char *str, char *old, char *new) {
	// Declare a string variable to hold the result of the replacement
	char res[1000];
	
	// Declare a pointer to the current position in the string `str`
	char *p = str;
	
	// Declare a pointer to the current position in the string `old`
	char *q = old;
	
	// Declare a pointer to the current position in the string `new`
	char *r = new;
	
	// Declare a boolean variable to indicate whether a match has been found
	int found = 0;
	
	// Loop until the end of the string `str` is reached
	while (*p!= '\0') {
		// If the current character in the string `str` matches the current character in the string `old`
		if (*p == *q) {
			// Set the boolean variable `found` to true
			found = 1;
			
			// Loop until the end of the string `old` is reached
			while (*q!= '\0') {
				// If the current character in the string `old` matches the current character in the string `new`
				if (*q == *r) {
					// Append the current character in the string `new` to the string `res`
					*res = *r;
					
					// Increment the pointer `r`
					r++;
				} else {
					// Append the current character in the string `str` to the string `res`
					*res = *p;
				}
				
				// Increment the pointer `p`
				p++;
				// Increment the pointer `q`
				q++;
				// Increment the pointer `res`
				res++;
			}
			
			// If the boolean variable `found` is true
			if (found) {
				// Set the boolean variable `found` to false
				found = 0;
			} else {
				// Append the current character in the string `str` to the string `res`
				*res = *p;
			}
		} else {
			// Append the current character in the string `str` to the string `res`
			*res = *p;
		}
		
		// Increment the pointer `p`
		p++;
		// Increment the pointer `res`
		res++;
	}
	
	// Set the last character in the string `res` to the null character
	*res = '\0';
	
	// Copy the string `res` to the string `str`
	strcpy(str, res);
}

