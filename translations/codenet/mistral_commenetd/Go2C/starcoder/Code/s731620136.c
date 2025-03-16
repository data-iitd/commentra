#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
typedef struct {
	char *buffer;
	size_t length;
	size_t capacity;
	FILE *fptr;
} Buffer;

Buffer *new_buffer() {
	Buffer *b = malloc(sizeof(Buffer));
	b->buffer = NULL;
	b->length = 0;
	b->capacity = 0;
	b->fptr = NULL;
	return b;
}

void free_buffer(Buffer *b) {
	if (b->fptr) {
		free(b->fptr);
	}
	free(b->buffer);
	free(b);
}

void buffer_append(Buffer *b, char c) {
	if (b->length == b->capacity) {
		b->capacity = (b->capacity == 0)? 2 : b->capacity * 2;
		b->buffer = realloc(b->buffer, b->capacity);
	}
	b->buffer[b->length++] = c;
}

void buffer_append_str(Buffer *b, char *s) {
	while (*s) {
		buffer_append(b, *s++);
	}
}

void buffer_append_buffer(Buffer *b, Buffer *s) {
	buffer_append_str(b, s->buffer);
}

void buffer_print(Buffer *b) {
	fwrite(b->buffer, 1, b->length, stdout);
}

void buffer_read_file(Buffer *b, FILE *fptr) {
	if (b->fptr) {
		free(b->fptr);
	}
	b->fptr = fptr;
	fseek(fptr, 0, SEEK_END);
	b->length = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	b->capacity = b->length;
	b->buffer = realloc(b->buffer, b->capacity);
	fread(b->buffer, 1, b->length, fptr);
}

Buffer *buffer_from_file(FILE *fptr) {
	Buffer *b = new_buffer();
	buffer_read_file(b, fptr);
	return b;
}

//... (rest of the Buffer methods)

typedef struct {
	char *buffer;
	size_t length;
	size_t capacity;
	FILE *fptr;
} Scanner;

Scanner *new_scanner() {
	Scanner *s = malloc(sizeof(Scanner));
	s->buffer = NULL;
	s->length = 0;
	s->capacity = 0;
	s->fptr = NULL;
	return s;
}

void free_scanner(Scanner *s) {
	if (s->fptr) {
		free(s->fptr);
	}
	free(s->buffer);
	free(s);
}

void scanner_append(Scanner *s, char c) {
	if (s->length == s->capacity) {
		s->capacity = (s->capacity == 0)? 2 : s->capacity * 2;
		s->buffer = realloc(s->buffer, s->capacity);
	}
	s->buffer[s->length++] = c;
}

void scanner_append_str(Scanner *s, char *str) {
	while (*str) {
		scanner_append(s, *str++);
	}
}

void scanner_append_scanner(Scanner *s, Scanner *other) {
	scanner_append_str(s, other->buffer);
}

void scanner_print(Scanner *s) {
	printf("%s", s->buffer);
}

void scanner_read_file(Scanner *s, FILE *fptr) {
	if (s->fptr) {
		free(s->fptr);
	}
	s->fptr = fptr;
	fseek(fptr, 0, SEEK_END);
	s->length = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	s->capacity = s->length;
	s->buffer = realloc(s->buffer, s->capacity);
	fread(s->buffer, 1, s->length, fptr);
}

Scanner *scanner_from_file(FILE *fptr) {
	Scanner *s = new_scanner();
	scanner_read_file(s, fptr);
	return s;
}

//... (rest of the Scanner methods)

int run(FILE *input, FILE *output) {
	Scanner *sc = new_scanner();
	scanner_read_file(sc, input);

	int N = scanner_next_int(sc);

	//... (empty block for N == 0 case)

	if (N < 4) { // Check if N is less than 4
		fprintf(output, "0\n"); // Print 0 if N is less than 4
		return 0; // Return 0
	}

	//... (variable initialization block)

	int nr, nb, ng; // Declare and initialize variables for red, blue, and green balls
	nr = nb = ng = 0;

	for (int i = 0; i < N; i++) { // Iterate through each character in the string S
		if (S[i] == 'R') { // If the character is 'R'
			nr++; // Increment the nr counter
		}

		if (S[i] == 'B') { // If the character is 'B'
			nb++; // Increment the nb counter
		}

		if (S[i] == 'G') { // If the character is 'G'
			ng++; // Increment the ng counter
		}
	}

	int same = 0; // Initialize a counter for the number of same-colored groups of three balls

	//... (outer loop block)

	for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
		int i = 0; // Initialize index i to 0
		int j = 1 * a; // Initialize index j to a multiplied by 1
		int k = 2 * a; // Initialize index k to a multiplied by 2

		//... (inner loop block)

		for (k = 2 * a; k < N; k++) { // Iterate through each index k from a*2 to N-1
			//... (check condition block)

			if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) { // Check if the balls at indices i, j, and k have different colors
				same++; // If so, increment the same counter
			}

			//... (update indices block)

			i++; // Increment index i
			j++; // Increment index j
			k++; // Increment index k
		}
	}

	int tot = nr * nb * ng; // Calculate the total number of balls

	//... (comment out or remove the following lines as they are not used in the final solution)

	// int tot = 0; // Initialize a variable for the total number of balls
	// int sum = 0; // Initialize a variable for the number of distinct triples
	// int sum2 = 0; // Initialize a variable for the number of distinct triples with the same middle index

	//... (calculate the final result)

	fprintf(output, "%d\n", tot - same); // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

	return 0; // Return 0 to indicate successful execution
}

int main() {
	FILE *input = stdin;
	FILE *output = stdout;
	return run(input, output);
}

