#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// getScanner initializes a new bufio.Scanner to read from a file.
// It sets the split function to bufio.ScanWords to read words,
// and it also sets a buffer size.
struct bufio_scanner {
	FILE *fp;
	char *buffer;
	size_t buffer_size;
	size_t buffer_pos;
	size_t buffer_end;
	int eof;
};

struct bufio_scanner *get_scanner(FILE *fp) {
	struct bufio_scanner *scanner = malloc(sizeof(struct bufio_scanner));
	scanner->fp = fp;
	scanner->buffer = NULL;
	scanner->buffer_size = 0;
	scanner->buffer_pos = 0;
	scanner->buffer_end = 0;
	scanner->eof = 0;
	return scanner;
}

void free_scanner(struct bufio_scanner *scanner) {
	free(scanner->buffer);
	free(scanner);
}

// getNextString reads the next word from the scanner and returns it as a string.
char *get_next_string(struct bufio_scanner *scanner) {
	if (scanner->eof) {
		return NULL;
	}
	if (scanner->buffer_pos == scanner->buffer_end) {
		scanner->buffer_size = fread(scanner->buffer, 1, 500000, scanner->fp);
		scanner->buffer_pos = 0;
		scanner->buffer_end = scanner->buffer_size;
		if (scanner->buffer_size == 0) {
			scanner->eof = 1;
			return NULL;
		}
	}
	char *start = scanner->buffer + scanner->buffer_pos;
	scanner->buffer_pos = scanner->buffer_pos + 1;
	while (scanner->buffer_pos < scanner->buffer_end && scanner->buffer[scanner->buffer_pos]!='') {
		scanner->buffer_pos = scanner->buffer_pos + 1;
	}
	char *end = scanner->buffer + scanner->buffer_pos;
	scanner->buffer_pos = scanner->buffer_pos + 1;
	char *ret = malloc(end - start + 1);
	memcpy(ret, start, end - start);
	ret[end - start] = 0;
	return ret;
}

// getNextInt reads the next word from the scanner, converts it to an integer,
// and returns it.
int get_next_int(struct bufio_scanner *scanner) {
	char *s = get_next_string(scanner);
	int ret = atoi(s);
	free(s);
	return ret;
}

// getNextInt64 reads the next word from the scanner, converts it to an int64,
// and returns it.
int64_t get_next_int64(struct bufio_scanner *scanner) {
	char *s = get_next_string(scanner);
	int64_t ret = atoll(s);
	free(s);
	return ret;
}

// main is the entry point of the program.
// It first checks if a file name is provided as an argument,
// and if so, it opens that file for reading.
// It then initializes a scanner and a writer.
int main(int argc, char **argv) {
	FILE *fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}
	struct bufio_scanner *scanner = get_scanner(fp);

	// Read the number of elements.
	int n = get_next_int(scanner);

	// Initialize a slice to store the elements and a sum variable.
	int *aa = malloc(sizeof(int) * (n + 2));
	int sum = 0;

	// Read the elements into the slice and calculate the sum of absolute differences.
	for (int i = 0; i < n; i++) {
		aa[i + 1] = get_next_int(scanner);
		sum += abs(aa[i + 1] - aa[i]);
	}
	sum += abs(aa[n + 1] - aa[n]);

	// Calculate and print the differences for each element.
	for (int i = 1; i < n + 1; i++) {
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		printf("%d\n", ans);
	}

	free_scanner(scanner);
	return 0;
}

