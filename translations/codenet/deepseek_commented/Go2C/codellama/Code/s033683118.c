#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner to read input from a file.
// It sets the split function to scan words and buffers the input to a specified size.
void getScanner(FILE *fp) {
	char buf[500001];
	fgets(buf, 500001, fp);
	char *token = strtok(buf, " ");
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}

// getNextString reads the next token from the scanner and returns it as a string.
char *getNextString(FILE *fp) {
	char buf[500001];
	fgets(buf, 500001, fp);
	return buf;
}

// getNextInt reads the next token, converts it to an integer, and returns it.
int getNextInt(FILE *fp) {
	char buf[500001];
	fgets(buf, 500001, fp);
	return atoi(buf);
}

// getNextInt64 reads the next token, converts it to an int64, and returns it.
int64_t getNextInt64(FILE *fp) {
	char buf[500001];
	fgets(buf, 500001, fp);
	return atoll(buf);
}

// getNextUint64 reads the next token, converts it to a uint64, and returns it.
uint64_t getNextUint64(FILE *fp) {
	char buf[500001];
	fgets(buf, 500001, fp);
	return strtoull(buf, NULL, 10);
}

// getNextFloat64 reads the next token, converts it to a float64, and returns it.
double getNextFloat64(FILE *fp) {
	char buf[500001];
	fgets(buf, 500001, fp);
	return atof(buf);
}

// main function handles the program's flow.
// It sets up the input and output files based on environment variables,
// calls the solve function, and prints separators if necessary.
int main() {
	FILE *fp = stdin;
	FILE *wfp = stdout;
	int cnt = 0;

	if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2;
	}
	if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	getScanner(fp);
	FILE *writer = fopen("output.txt", "w");
	solve(fp, writer);
	for (int i = 0; i < cnt; i++) {
		fprintf(writer, "-----------------------------------\n");
		solve(fp, writer);
	}
	fclose(writer);
}

// solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
// It writes "Yes" or "No" based on this condition.
void solve(FILE *fp, FILE *writer) {
	int k = getNextInt(fp);
	int x = getNextInt(fp);

	char *ans = "No";
	if (k*500 >= x) {
		ans = "Yes";
	}
	fprintf(writer, "%s\n", ans);
}

