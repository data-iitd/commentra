#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize logger to include short file names
void main() {
	log.SetFlags(log.Lshortfile)
	
	// Create a new scanner to read input
	scanner sc = newScanner();
	
	// Read two integers from the input
	int x = sc.nextInt();
	int y = sc.nextInt();
	
	// Define an array containing three slices, each representing a group of months with the same number of days
	int xt, yt;
	int a[3][12] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
	
	// Iterate over the array to determine which group each of the integers belongs to
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 12; j++) {
			// log.Println(n) // Uncomment to log each number in the array
			if (x == a[i][j]) {
				xt = i;
			}
			if (y == a[i][j]) {
				yt = i;
			}
		}
	}
	
	// Compare the groups of x and y to determine if they belong to the same group
	if (xt == yt) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Custom scanner struct to read input
typedef struct {
	FILE *r;
	char *buf;
	int p;
} scanner;

// Function to create a new scanner
scanner newScanner() {
	scanner sc;
	sc.r = stdin;
	sc.buf = (char *) malloc(1000 * sizeof(char));
	sc.p = 0;
	return sc;
}

// Function to read the next word
char *next(scanner *s) {
	s->pre();
	int start = s->p;
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			break;
		}
	}
	char *result = (char *) malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

// Function to read the next line
char *nextLine(scanner *s) {
	s->pre();
	int start = s->p;
	s->p = strlen(s->buf);
	char *result = (char *) malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// Function to read the next integer
int nextInt(scanner *s) {
	char *v = next(s);
	int result = atoi(v);
	free(v);
	return result;
}

// Function to preprocess the buffer
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) {
		s->readLine();
		s->p = 0;
	}
}

// Function to read a line from the input
void readLine(scanner *s) {
	s->buf = (char *) malloc(1000 * sizeof(char));
	for (;;) {
		char *l = (char *) malloc(1000 * sizeof(char));
		int p = fgets(l, 1000, s->r);
		s->buf = (char *) realloc(s->buf, strlen(s->buf) + strlen(l) + 1);
		strcat(s->buf, l);
		if (!p) {
			break;
		}
	}
}

