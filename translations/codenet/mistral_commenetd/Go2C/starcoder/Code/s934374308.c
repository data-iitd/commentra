#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Initialize variables
	int N, K, R, S, P;
	char T[1000000];

	// Read input from standard input
	scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
	scanf("%s", T);

	// Initialize dictionary to store the count of each character
	int dict[3] = {0, 0, 0};

	// Initialize boolean arrays to represent the state of each character
	char char;
	bool s[1000000] = {true};
	bool r[1000000] = {true};
	bool p[1000000] = {true};

	// Initialize all characters to be in the 'on' state
	for (int i = 0; i < N; i++) {
		s[i] = true;
	}

	// Iterate through each character in the input string
	for (int i = 0; i < strlen(T); i++) {
		// Assign the current character to a variable
		char = T[i];

		// Check if we have reached the window size
		if (i >= K) {
			// If the current character is a substring of the previous K characters, toggle the state of the character
			if (char == T[i-K]) {
				switch (char) {
				case's':
					// Toggle the state of the character at index i%K
					if (s[i%K]) {
						s[i%K] = false;
						continue;
					} else {
						s[i%K] = true;
					}

				case 'r':
					// Toggle the state of the character at index i%K
					if (r[i%K]) {
						r[i%K] = false;
						continue;
					} else {
						r[i%K] = true;

					}

				case 'p':
					// Toggle the state of the character at index i%K
					if (p[i%K]) {
						p[i%K] = false;
						continue;
					} else {
						p[i%K] = true;

					}
				}

			// If the current character is not a substring of the previous K characters, update the state of the characters accordingly
			} else {
				switch (char) {
				case's':
					// Set the state of the character at index i%K to 'on'
					s[i%K] = true;
				case 'r':
					// Set the state of the character at index i%K to 'on'
					r[i%K] = true;
				case 'p':
					// Set the state of the character at index i%K to 'on'
					p[i%K] = true;
				}

			}
		}

		// Update the dictionary with the count of the current character
		switch (char) {
		case's':
			dict[0] = dict[0] + 1;
		case 'r':
			dict[1] = dict[1] + 1;
		case 'p':
			dict[2] = dict[2] + 1;
		}
	}

	// Calculate and print the result
	int res = P*dict[1] + S*dict[2] + R*dict[0];
	printf("%d\n", res);

}

