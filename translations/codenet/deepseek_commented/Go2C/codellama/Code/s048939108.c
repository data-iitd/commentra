
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Main function starts here
int main() {
	// Initialize a new scanner to read input
	scanner sc;
	// Read the next string from the scanner
	char *S = sc.next();
	// Check if the string S starts with the prefix "YAKI"
	if (strncmp(S, "YAKI", 4) == 0) {
		// If it does, print "Yes"
		printf("Yes\n");
	} else {
		// Otherwise, print "No"
		printf("No\n");
	}
	return 0;
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function to find the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Custom scanner type to handle input reading
typedef struct {
	char *buf;
	int p;
} scanner;

// Function to create a new scanner instance
scanner newScanner() {
	scanner sc;
	sc.buf = (char *)malloc(1000 * sizeof(char));
	sc.p = 0;
	return sc;
}

// Method to read the next word from the input
char *next(scanner *s) {
	s->pre();
	int start = s->p;
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			break;
		}
	}
	char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

// Method to read the next line from the input
char *nextLine(scanner *s) {
	s->pre();
	int start = s->p;
	s->p = strlen(s->buf);
	char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// Method to read the next integer from the input
int nextInt(scanner *s) {
	char *v = s->next();
	int result = atoi(v);
	free(v);
	return result;
}

// Method to read the next array of integers from the input
int *nextIntArray(scanner *s) {
	s->pre();
	int start = s->p;
	int *result = (int *)malloc(1000 * sizeof(int));
	int i = 0;
	for (; s->p < strlen(s->buf) + 1; s->p++) {
		if (s->p == strlen(s->buf) || s->buf[s->p] == ' ') {
			char *v = (char *)malloc((s->p - start + 1) * sizeof(char));
			strncpy(v, s->buf + start, s->p - start);
			v[s->p - start] = '\0';
			result[i] = atoi(v);
			free(v);
			start = s->p + 1;
			i++;
		}
	}
	return result;
}

// Method to preprocess the buffer before reading
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) {
		s->readLine();
		s->p = 0;
	}
}

// Method to read a line from the input and update the buffer
void readLine(scanner *s) {
	s->buf = (char *)malloc(1000 * sizeof(char));
	for (;;) {
		char *l = (char *)malloc(1000 * sizeof(char));
		int p = 0;
		int e = fgets(l, 1000, stdin);
		if (e != 0) {
			strcat(s->buf, l);
			if (!p) {
				break;
			}
		}
	}
}

