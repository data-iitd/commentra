
#include <stdio.h>
#include <string.h>

int main() {
	// Read the two strings S and T from standard input
	char S[100000], T[100000];
	scanf("%s %s", S, T);
	
	// Initialize the maximum number of matching characters to 0
	int max = 0;
	
	// Iterate over the possible starting positions of the substring of S that is the same length as T
	for (int i = 0; i <= strlen(S) - strlen(T); i++) {
		// Initialize a counter for the number of matching characters in the current substring
		int c = 0;
		
		// Check each character in the current substring against the corresponding character in T
		for (int j = 0; j < strlen(T); j++) {
			if (S[i+j] == T[j]) {
				// Increment the counter if the characters match
				c++;
			}
		}
		
		// Update max if the current count of matching characters is greater than the previous max
		if (max < c) {
			max = c;
		}
	}
	
	// Print the number of characters that need to be changed to make S contain T as a substring
	printf("%d\n", strlen(T) - max);
}

