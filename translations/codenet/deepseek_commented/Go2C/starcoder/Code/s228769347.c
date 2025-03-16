#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <float.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

// getScanner initializes a new Scanner to read from a file pointer.
// It sets the split function to ScanWords and buffers to 500001 bytes.
struct bufio_scanner {
	FILE *fp;
	char *buffer;
	size_t buffer_size;
	size_t buffer_pos;
	size_t buffer_last;
	bool eof;
	bool error;
	bool overflow;
	bool unget;
	int unget_char;
};

struct bufio_scanner *bufio_scanner_new(FILE *fp) {
	struct bufio_scanner *scanner = malloc(sizeof(struct bufio_scanner));
	scanner->fp = fp;
	scanner->buffer = malloc(500001);
	scanner->buffer_size = 500001;
	scanner->buffer_pos = 0;
	scanner->buffer_last = 0;
	scanner->eof = false;
	scanner->error = false;
	scanner->overflow = false;
	scanner->unget = false;
	scanner->unget_char = 0;
	return scanner;
}

void bufio_scanner_free(struct bufio_scanner *scanner) {
	free(scanner->buffer);
	free(scanner);
}

void bufio_scanner_unget(struct bufio_scanner *scanner, int c) {
	assert(c!= EOF);
	scanner->unget = true;
	scanner->unget_char = c;
}

int bufio_scanner_get(struct bufio_scanner *scanner) {
	if (scanner->unget) {
		scanner->unget = false;
		return scanner->unget_char;
	}
	if (scanner->buffer_pos == scanner->buffer_last) {
		if (scanner->eof) {
			return EOF;
		}
		scanner->buffer_pos = 0;
		scanner->buffer_last = fread(scanner->buffer, 1, scanner->buffer_size, scanner->fp);
		if (ferror(scanner->fp)) {
			scanner->error = true;
			return EOF;
		}
		if (scanner->buffer_last == 0) {
			scanner->eof = true;
			return EOF;
		}
	}
	int c = scanner->buffer[scanner->buffer_pos];
	scanner->buffer_pos++;
	return c;
}

void bufio_scanner_unget_string(struct bufio_scanner *scanner, char *s) {
	while (*s) {
		bufio_scanner_unget(scanner, *s);
		s++;
	}
}

void bufio_scanner_unget_string_len(struct bufio_scanner *scanner, char *s, size_t n) {
	while (n) {
		bufio_scanner_unget(scanner, *s);
		s++;
		n--;
	}
}

void bufio_scanner_unget_string_len(struct bufio_scanner *scanner, char *s, size_t n) {
	while (n) {
		bufio_scanner_unget(scanner, *s);
		s++;
		n--;
	}
}

// getNextString reads the next token from the Scanner and returns it as a string.
char *bufio_scanner_get_next_string(struct bufio_scanner *scanner) {
	char *s = malloc(1000000);
	size_t i = 0;
	while (true) {
		int c = bufio_scanner_get(scanner);
		if (c == EOF || c =='' || c == '\n' || c == '\t' || c == '\r') {
			break;
		}
		if (i == 1000000) {
			s = realloc(s, 2000000);
			i = 1999999;
		}
		s[i] = c;
		i++;
	}
	s[i] = 0;
	return s;
}

// getNextInt reads the next token as a string, converts it to an integer, and returns it.
int bufio_scanner_get_next_int(struct bufio_scanner *scanner) {
	char *s = bufio_scanner_get_next_string(scanner);
	int i = atoi(s);
	free(s);
	return i;
}

// getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
int64_t bufio_scanner_get_next_int64(struct bufio_scanner *scanner) {
	char *s = bufio_scanner_get_next_string(scanner);
	int64_t i = atoll(s);
	free(s);
	return i;
}

// getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
uint64_t bufio_scanner_get_next_uint64(struct bufio_scanner *scanner) {
	char *s = bufio_scanner_get_next_string(scanner);
	uint64_t i = atoll(s);
	free(s);
	return i;
}

// getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
double bufio_scanner_get_next_float64(struct bufio_scanner *scanner) {
	char *s = bufio_scanner_get_next_string(scanner);
	double i = atof(s);
	free(s);
	return i;
}

// main function handles file input/output based on command-line arguments.
// It reads integers from the specified file or standard input, sorts them,
// and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
int main(int argc, char *argv[]) {
	struct bufio_scanner *scanner;
	FILE *fp;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	} else {
		fp = stdin;
	}
	scanner = bufio_scanner_new(fp);

	// Read the number of elements.
	int n = bufio_scanner_get_next_int(scanner);
	int *ll = malloc(n * sizeof(int));

	// Read n integers into the slice ll.
	for (int i = 0; i < n; i++) {
		ll[i] = bufio_scanner_get_next_int(scanner);
	}

	// Sort the slice ll.
	qsort(ll, n, sizeof(int), int_compare);

	// Initialize the answer variable.
	int ans = 0;

	// Iterate through possible triplets (i, j, m) where i < j < m.
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			int l = j + 1;
			int r = n;
			while (l < r) {
				int m = (l + r) >> 1;
				if (ll[m] < ll[i]+ll[j]) {
					l = m + 1;
					continue;
				}
				r = m;
			}

			// Add the number of valid m's to the answer.
			ans += l - (j + 1);
		}
	}

	// Print the final answer to the standard output.
	printf("%d\n", ans);

	// Flush the writer to ensure all data is written to the file or standard output.
	fflush(stdout);

	bufio_scanner_free(scanner);
	return 0;
}

int int_compare(const void *a, const void *b) {
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y) {
		return -1;
	}
	if (x > y) {
		return 1;
	}
	return 0;
}

