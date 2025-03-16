
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes and returns a new bufio.Scanner from the given file pointer
void getScanner(FILE *fp) {
	// initialize scanner
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	// read input
	fgets(buf, 500000, fp);
	// split input
	char *token = strtok(buf, " ");
	// iterate through input
	while (token != NULL) {
		// read next word
		token = strtok(NULL, " ");
	}
	// free memory
	free(buf);
}

// getNextString reads and returns the next word as a string from the scanner
char *getNextString(FILE *fp) {
	// initialize scanner
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	// read input
	fgets(buf, 500000, fp);
	// split input
	char *token = strtok(buf, " ");
	// iterate through input
	while (token != NULL) {
		// read next word
		token = strtok(NULL, " ");
	}
	// free memory
	free(buf);
	return token;
}

// getNextInt reads and converts the next integer from the scanner to an int
int getNextInt(FILE *fp) {
	// initialize scanner
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	// read input
	fgets(buf, 500000, fp);
	// split input
	char *token = strtok(buf, " ");
	// iterate through input
	while (token != NULL) {
		// read next word
		token = strtok(NULL, " ");
	}
	// free memory
	free(buf);
	return atoi(token);
}

// getNextInt64 reads and converts the next integer from the scanner to an int64
int64_t getNextInt64(FILE *fp) {
	// initialize scanner
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	// read input
	fgets(buf, 500000, fp);
	// split input
	char *token = strtok(buf, " ");
	// iterate through input
	while (token != NULL) {
		// read next word
		token = strtok(NULL, " ");
	}
	// free memory
	free(buf);
	return atoll(token);
}

// getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
uint64_t getNextUint64(FILE *fp) {
	// initialize scanner
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	// read input
	fgets(buf, 500000, fp);
	// split input
	char *token = strtok(buf, " ");
	// iterate through input
	while (token != NULL) {
		// read next word
		token = strtok(NULL, " ");
	}
	// free memory
	free(buf);
	return strtoull(token, NULL, 10);
}

// getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
float64_t getNextFloat64(FILE *fp) {
	// initialize scanner
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	// read input
	fgets(buf, 500000, fp);
	// split input
	char *token = strtok(buf, " ");
	// iterate through input
	while (token != NULL) {
		// read next word
		token = strtok(NULL, " ");
	}
	// free memory
	free(buf);
	return strtod(token, NULL);
}

// main function is the entry point of the program
int main(int argc, char *argv[]) {
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
	getScanner(fp);
	// read the first integer from the input
	int n = getNextInt(fp);

	// initialize answer variable
	char *ans = "second";
	// iterate through the input integers
	for (int i = 0; i < n; i++) {
		// read the next integer from the input
		int a = getNextInt(fp);
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

	// close input and output files
	fclose(fp);
	fclose(wfp);

	return 0;
}

