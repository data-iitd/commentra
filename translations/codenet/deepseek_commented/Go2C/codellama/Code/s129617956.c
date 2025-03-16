#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	// Read an integer n from the standard input
	int n = nextInt();
	
	// Calculate the square root of n and store it in rt
	int rt = (int)sqrt(n);
	
	// Initialize minf to 100, which will hold the minimum number of digits
	int minf = 100;
	
	// Iterate from 1 to rt + 1 to find divisors of n
	for (int i = 1; i < rt+1; i++) {
		if (n%i == 0) {
			// If i is a divisor of n, calculate the quotient b
			int b = n / i;
			
			// Count the number of digits in b
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			
			// Update minf with the minimum number of digits found
			minf = min(minf, ndigit);
		}
	}
	
	// Print the minimum number of digits
	printf("%d\n", minf);
	
	return 0;
}

// Read a line from the standard input
char* nextLine() {
	char* line = (char*)malloc(1000000 * sizeof(char));
	char* buffer = (char*)malloc(1000000 * sizeof(char));
	int isPrefix = 1;
	int err;
	while (isPrefix) {
		line = fgets(buffer, 1000000, stdin);
		if (err != 0) {
			free(line);
			free(buffer);
			exit(1);
		}
		buffer = realloc(buffer, strlen(buffer) + 1000000);
	}
	return line;
}

// Split the input line into a string array
char** nextStringArray() {
	char* line = nextLine();
	char** s = (char**)malloc(1000000 * sizeof(char*));
	int n = 0;
	char* token = strtok(line, " ");
	while (token != NULL) {
		s[n] = (char*)malloc(1000000 * sizeof(char));
		strcpy(s[n], token);
		n++;
		token = strtok(NULL, " ");
	}
	free(line);
	return s;
}

// Read an integer from the standard input
int nextInt() {
	char* line = nextLine();
	int n = atoi(line);
	free(line);
	return n;
}

// Read an integer array from the standard input
int* nextIntArray() {
	char** s = nextStringArray();
	int n = strlen(s);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		a[i] = atoi(s[i]);
	}
	free(s);
	return a;
}

// Return the minimum of two integers
int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

