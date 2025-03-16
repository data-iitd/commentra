
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new bufio.Scanner from a file pointer
struct bufio_scanner *getScanner(FILE *fp) {
	struct bufio_scanner *scanner = (struct bufio_scanner *)malloc(sizeof(struct bufio_scanner));
	scanner->fp = fp;
	scanner->buf = (char *)malloc(500001);
	scanner->buf_size = 500000;
	scanner->buf_pos = 0;
	scanner->buf_end = 0;
	return scanner;
}

// Function to read the next string from the scanner
char *getNextString(struct bufio_scanner *scanner) {
	char *buf = scanner->buf;
	int buf_size = scanner->buf_size;
	int buf_pos = scanner->buf_pos;
	int buf_end = scanner->buf_end;
	int i = 0;
	while (buf[buf_pos] != ' ' && buf_pos < buf_end) {
		buf_pos++;
		i++;
	}
	char *str = (char *)malloc(i + 1);
	memcpy(str, buf + buf_pos - i, i);
	str[i] = '\0';
	scanner->buf_pos = buf_pos;
	return str;
}

// Function to read the next integer from the scanner
int getNextInt(struct bufio_scanner *scanner) {
	char *str = getNextString(scanner);
	int i = atoi(str);
	free(str);
	return i;
}

// Function to read the next int64 from the scanner
long long getNextInt64(struct bufio_scanner *scanner) {
	char *str = getNextString(scanner);
	long long i = atoll(str);
	free(str);
	return i;
}

// Function to calculate the absolute value of an integer
int absint(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Main function
int main() {
	// Open the standard input as a file
	FILE *fp = stdin;
	// If there is an argument, open the file with that name instead
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Create a new bufio.Scanner from the file pointer
	struct bufio_scanner *scanner = getScanner(fp);

	// Create a new bufio.Writer for output
	struct bufio_writer *writer = (struct bufio_writer *)malloc(sizeof(struct bufio_writer));
	writer->fp = stdout;
	writer->buf = (char *)malloc(500001);
	writer->buf_size = 500000;
	writer->buf_pos = 0;
	writer->buf_end = 0;

	// Read the first integer from the input
	int n = getNextInt(scanner);

	// Initialize an array 'aa' of size 'n+2'
	int *aa = (int *)malloc((n + 2) * sizeof(int));
	// Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
	int sum = 0;

	// Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
	for (int i = 0; i < n; i++) {
		// Read the next integer from the scanner and store it in 'aa[i+1]'
		aa[i + 1] = getNextInt(scanner);
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
		fprintf(writer->fp, "%d\n", ans);
	}

	// Flush the buffer to write all the data to the output
	fflush(writer->fp);

	// Free the memory allocated for the array 'aa'
	free(aa);
	// Free the memory allocated for the scanner
	free(scanner);
	// Free the memory allocated for the writer
	free(writer);

	return 0;
}

