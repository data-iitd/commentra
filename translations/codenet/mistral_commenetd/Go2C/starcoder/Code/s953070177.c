
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <fenv.h>
#include <inttypes.h>
#include <complex.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdnoreturn.h>
#include <tgmath.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

// Function to create a new bufio.Scanner from a file pointer
struct bufio_scanner *get_scanner(FILE *fp) {
	struct bufio_scanner *scanner = malloc(sizeof(struct bufio_scanner));
	scanner->fp = fp;
	scanner->buffer = malloc(500001 * sizeof(char));
	scanner->buffer_size = 500000;
	scanner->buffer_pos = 0;
	scanner->buffer_end = 0;
	return scanner;
}

// Function to read the next string from the scanner
char *get_next_string(struct bufio_scanner *scanner) {
	while (scanner->buffer_pos == scanner->buffer_end) {
		scanner->buffer_pos = 0;
		scanner->buffer_end = fread(scanner->buffer, sizeof(char), scanner->buffer_size, scanner->fp);
	}
	char *ret = malloc(sizeof(char) * (scanner->buffer_end - scanner->buffer_pos + 1));
	memcpy(ret, scanner->buffer + scanner->buffer_pos, scanner->buffer_end - scanner->buffer_pos);
	ret[scanner->buffer_end - scanner->buffer_pos] = '\0';
	scanner->buffer_pos = scanner->buffer_end + 1;
	return ret;
}

// Function to read the next integer from the scanner
int get_next_int(struct bufio_scanner *scanner) {
	char *s = get_next_string(scanner);
	int ret = atoi(s);
	free(s);
	return ret;
}

// Function to read the next int64 from the scanner
int64_t get_next_int64(struct bufio_scanner *scanner) {
	char *s = get_next_string(scanner);
	int64_t ret = atoll(s);
	free(s);
	return ret;
}

// Main function
int main(int argc, char **argv) {
	// Open the standard input as a file
	FILE *fp = stdin;
	// If there is an argument, open the file with that name instead
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Create a new bufio.Scanner from the file pointer
	struct bufio_scanner *scanner = get_scanner(fp);

	// Create a new bufio.Writer for output
	struct bufio_writer *writer = bufio_new_writer(stdout);

	// Read the first integer from the input
	int n = get_next_int(scanner);

	// Initialize an array 'aa' of size 'n+2'
	int *aa = malloc((n + 2) * sizeof(int));
	// Initialize a variable'sum' to store the sum of absolute differences between consecutive elements
	int64_t sum = 0;

	// Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
	for (int i = 0; i < n; i++) {
		// Read the next integer from the scanner and store it in 'aa[i+1]'
		aa[i + 1] = get_next_int(scanner);
		// Calculate the absolute difference between the current and previous elements and add it to the sum
		sum += absint(aa[i + 1] - aa[i]);
	}
	// Calculate the absolute difference between the last two elements and add it to the sum
	sum += absint(aa[n + 1] - aa[n]);

	// Iterate through the array 'aa' and print the answer for each subarray
	for (int i = 1; i < n + 1; i++) {
		// Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
		int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
		// Write the answer to the output writer
		bufio_write_int(writer, ans);
		bufio_write_char(writer, '\n');
	}

	// Flush the buffer to write all the data to the output
	bufio_flush(writer);

	// Close the file pointer
	fclose(fp);
	// Close the output writer
	bufio_free_writer(writer);
	// Free the scanner
	free(scanner);
	return 0;
}

// Function to calculate the absolute value of an integer
int absint(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

