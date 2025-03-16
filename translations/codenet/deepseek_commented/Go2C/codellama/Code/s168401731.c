#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new bufio.Scanner with specific configurations.
void getScanner(FILE *fp) {
	char *buf = (char *)malloc(500001 * sizeof(char));
	buf[500000] = '\0';
	fscanf(fp, "%s", buf);
	free(buf);
}

// getNextString reads the next word from the scanner.
char *getNextString(FILE *fp) {
	char *buf = (char *)malloc(500001 * sizeof(char));
	fscanf(fp, "%s", buf);
	return buf;
}

// getNextInt reads the next word, converts it to an integer, and returns it.
int getNextInt(FILE *fp) {
	char *buf = getNextString(fp);
	int i = atoi(buf);
	free(buf);
	return i;
}

// getNextInt64 reads the next word, converts it to an int64, and returns it.
int64_t getNextInt64(FILE *fp) {
	char *buf = getNextString(fp);
	int64_t i = atoll(buf);
	free(buf);
	return i;
}

// getNextUint64 reads the next word, converts it to a uint64, and returns it.
uint64_t getNextUint64(FILE *fp) {
	char *buf = getNextString(fp);
	uint64_t i = strtoull(buf, NULL, 10);
	free(buf);
	return i;
}

// getNextFloat64 reads the next word, converts it to a float64, and returns it.
double getNextFloat64(FILE *fp) {
	char *buf = getNextString(fp);
	double i = atof(buf);
	free(buf);
	return i;
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char *argv[]) {
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// Check if command-line arguments are provided for file input/output.
	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	getScanner(fp);
	fprintf(wfp, "%s\n", "second");
	fclose(fp);
	fclose(wfp);
	return 0;
}

