#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read two strings S and T from standard input
	char S[1000], T[1000];
	scanf("%s %s", S, T);
	
	// Initialize a variable to keep track of the maximum number of matching characters
	int max = 0;
	
	// Iterate over each possible starting index in S where T can fit
	for (int i = 0; i <= strlen(S) - strlen(T); i++) {
		// Initialize a counter for matching characters
		int c = 0;
		
		// Compare characters of T with the corresponding characters in S
		for (int j = 0; j < strlen(T); j++) {
			if S[i+j] == T[j] {
				c++; // Increment the counter for each matching character
			}
		}
		
		// Update the maximum count of matching characters if the current count is greater
		if (max < c) {
			max = c;
		}
	}
	
	// Output the number of characters in T that do not match with S
	printf("%d\n", strlen(T) - max);
	
	return 0;
}
