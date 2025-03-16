#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 500001

typedef struct {
	char *buffer;
	int buffer_size;
	int buffer_index;
} Scanner;

Scanner *getScanner(FILE *fp) {
	Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
	scanner->buffer = (char *)malloc(MAX_BUFFER_SIZE);
	scanner->buffer_size = MAX_BUFFER_SIZE;
	scanner->buffer_index = 0;
	return scanner;
}

void getNextString(Scanner *scanner, char *str) {
	int i = 0;
	while (scanner->buffer[scanner->buffer_index] != ' ' && scanner->buffer[scanner->buffer_index] != '\0') {
		str[i++] = scanner->buffer[scanner->buffer_index++];
	}
	str[i] = '\0';
	scanner->buffer_index++;
}

int getNextInt(Scanner *scanner) {
	char str[100];
	getNextString(scanner, str);
	return atoi(str);
}

long long getNextInt64(Scanner *scanner) {
	char str[100];
	getNextString(scanner, str);
	return atoll(str);
}

unsigned long long getNextUint64(Scanner *scanner) {
	char str[100];
	getNextString(scanner, str);
	return strtoull(str, NULL, 10);
}

double getNextFloat64(Scanner *scanner) {
	char str[100];
	getNextString(scanner, str);
	return atof(str);
}

int main() {
	FILE *fp = stdin;
	FILE *wfp = stdout;

	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	Scanner *scanner = getScanner(fp);
	FILE *writer = fopen(wfp, "w");

	int n = getNextInt(scanner);

	char *ans = "second";
	for (int i = 0; i < n; i++) {
		int a = getNextInt(scanner);
		if (a % 2 == 1) {
			ans = "first";
			break;
		}
	}
	fprintf(writer, "%s\n", ans);
	fclose(writer);
	free(scanner->buffer);
	free(scanner);
	return 0;
}

