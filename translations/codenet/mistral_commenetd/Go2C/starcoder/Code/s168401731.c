
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes and returns a new bufio.Scanner from the given file pointer
struct bufio_scanner {
	FILE *fp;
	char *buffer;
	size_t buffer_size;
	size_t buffer_pos;
	size_t buffer_len;
};

struct bufio_scanner *get_scanner(FILE *fp) {
	struct bufio_scanner *scanner = malloc(sizeof(struct bufio_scanner));
	scanner->fp = fp;
	scanner->buffer = NULL;
	scanner->buffer_size = 0;
	scanner->buffer_pos = 0;
	scanner->buffer_len = 0;
	return scanner;
}

// getNextString reads and returns the next word as a string from the scanner
char *get_next_string(struct bufio_scanner *scanner) {
	if (scanner->buffer_pos == scanner->buffer_len) {
		scanner->buffer_pos = 0;
		scanner->buffer_len = fread(scanner->buffer, 1, scanner->buffer_size, scanner->fp);
	}
	char *token = malloc(sizeof(char) * 100);
	size_t i = 0;
	while (scanner->buffer_pos < scanner->buffer_len && scanner->buffer[scanner->buffer_pos]!='') {
		token[i] = scanner->buffer[scanner->buffer_pos];
		scanner->buffer_pos++;
		i++;
	}
	token[i] = '\0';
	return token;
}

// getNextInt reads and converts the next integer from the scanner to an int
int get_next_int(struct bufio_scanner *scanner) {
	char *token = get_next_string(scanner);
	int i = atoi(token);
	free(token);
	return i;
}

// getNextInt64 reads and converts the next integer from the scanner to an int64
int64_t get_next_int64(struct bufio_scanner *scanner) {
	char *token = get_next_string(scanner);
	int64_t i = atoll(token);
	free(token);
	return i;
}

// getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
uint64_t get_next_uint64(struct bufio_scanner *scanner) {
	char *token = get_next_string(scanner);
	uint64_t i = atoll(token);
	free(token);
	return i;
}

// getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
double get_next_float64(struct bufio_scanner *scanner) {
	char *token = get_next_string(scanner);
	double i = atof(token);
	free(token);
	return i;
}

// main function is the entry point of the program
int main(int argc, char **argv) {
	// open standard input as default file if no arguments are provided
	FILE *fp = stdin;
	// open output file if provided as an argument
	FILE *wfp = stdout;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
		// create output file if provided as an argument
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	// initialize scanner and writer
	struct bufio_scanner *scanner = get_scanner(fp);
	struct bufio_scanner *writer = get_scanner(wfp);

	// read the first integer from the input
	int n = get_next_int(scanner);

	// initialize answer variable
	char *ans = "second";
	// iterate through the input integers
	for (int i = 0; i < n; i++) {
		// read the next integer from the input
		int a = get_next_int(scanner);
		// check if the current integer is odd
		if (a % 2 == 1) {
			// update the answer if an odd integer is found
			ans = "first";
			// exit the loop if only one odd integer is found
			break;
		}
	}
	// write the answer to the output
	fprintf(wfp, "%s\n", ans);
	// flush the writer buffer
	fflush(wfp);



