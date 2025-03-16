#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, K, R, S, P;
	char T[1000001];
	scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
	scanf("%s", T);

	// Initialize the dictionary to keep track of the counts of 'r','s', and 'p'
	int dict[3] = {0, 0, 0};
	// Initialize a string to store the current character
	char char;
	// Initialize a boolean array to keep track of the availability of each choice for each player
	bool s[1000001] = {true};
	// Initialize all elements of the array to true
	for (int i = 0; i < N; i++) {
		s[i] = true;
	}
	// Create copies of the array for 'r', 'p'
	bool r[1000001] = {true};
	bool p[1000001] = {true};
	for (int i = 0; i < N; i++) {
		r[i] = s[i];
		p[i] = s[i];
	}

	// Iterate over each character in the string T
	for (int i = 0; i < strlen(T); i++) {
		char = T[i];
		// Check if the current index is greater than or equal to K
		if (i >= K) {
			// Check if the last K characters are the same as the current character
			if (char == T[i-K]) {
				// Update the availability of the choice based on the current character
				switch (char) {
					case's':
						if (s[i%K]) {
							s[i%K] = false;
							continue;
						} else {
							s[i%K] = true;
						}
						break;
					case 'r':
						if (r[i%K]) {
							r[i%K] = false;
							continue;
						} else {
							r[i%K] = true;
						}
						break;
					case 'p':
						if (p[i%K]) {
							p[i%K] = false;
							continue;
						} else {
							p[i%K] = true;
						}
						break;
				}
			} else {
				// Set the availability of the choice based on the current character
				switch (char) {
					case's':
						s[i%K] = true;
						break;
					case 'r':
						r[i%K] = true;
						break;
					case 'p':
						p[i%K] = true;
						break;
				}
			}
		}
		// Update the counts in the dictionary based on the current character
		switch (char) {
			case's':
				dict[0] = dict[0] + 1;
				break;
			case 'r':
				dict[1] = dict[1] + 1;
				break;
			case 'p':
				dict[2] = dict[2] + 1;
				break;
		}
	}

	// Calculate the result by multiplying the counts of 'r','s', and 'p' with their respective values (P, S, R)
	int res = P*dict[1] + S*dict[2] + R*dict[0];
	// Print the result
	printf("%d\n", res);
}

