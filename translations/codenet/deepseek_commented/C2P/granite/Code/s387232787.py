
#include <stdio.h>

// Array to store the count of each letter (a-z)
int c[26];

int main(void)
{
	// Array to store the input string
	char str[1200];
	
	// Read input strings until there are no more inputs
	while (scanf("%s", str) > 0) {
		// Pointer to traverse the string
		char *p = str;
		
		// Traverse each character in the string
		for ; *p; p++ {
			# Check if the character is a lowercase letter
			if 'a' <= *p and *p <= 'z':
				# Increment the count for the corresponding letter
				c[*p - 'a'] += 1
			
			# Check if the character is an uppercase letter
			elif 'A' <= *p and *p <= 'Z':
				# Increment the count for the corresponding letter
				c[*p - 'A'] += 1
		}
	}
	
	# Print the counts for each letter from 'a' to 'z'
	for i in range(26):
		print '%c : %d' % ('a' + i, c[i])
	
	return 0
}

