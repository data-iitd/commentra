#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 500001

void getScanner(FILE *fp, char *buffer, int *buffer_size, int *buffer_index) {
	*buffer_size = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, fp);
	*buffer_index = 0;
}

char *getNextString(char *buffer, int *buffer_index, int buffer_size) {
	char *start = buffer + *buffer_index;
	while (*buffer_index < buffer_size && buffer[*buffer_index] != ' ') {
		(*buffer_index)++;
	}
	buffer[*buffer_index] = '\0';
	return start;
}

int getNextInt(char *buffer, int *buffer_index, int buffer_size) {
	char *start = getNextString(buffer, buffer_index, buffer_size);
	return atoi(start);
}

long long getNextInt64(char *buffer, int *buffer_index, int buffer_size) {
	char *start = getNextString(buffer, buffer_index, buffer_size);
	return atoll(start);
}

unsigned long long getNextUint64(char *buffer, int *buffer_index, int buffer_size) {
	char *start = getNextString(buffer, buffer_index, buffer_size);
	return strtoull(start, NULL, 10);
}

double getNextFloat64(char *buffer, int *buffer_index, int buffer_size) {
	char *start = getNextString(buffer, buffer_index, buffer_size);
	return atof(start);
}

void solve(FILE *fp, FILE *wfp) {
	char buffer[MAX_BUFFER_SIZE];
	int buffer_size, buffer_index;
	getScanner(fp, buffer, &buffer_size, &buffer_index);

	int k = getNextInt(buffer, &buffer_index, buffer_size);
	int x = getNextInt(buffer, &buffer_index, buffer_size);

	char *ans = "No";
	if (k * 500 >= x) {
		ans = "Yes";
	}
	fprintf(wfp, "%s\n", ans);
}

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

	solve(fp, wfp);
	for (int i = 0; i < cnt; i++) {
		fprintf(wfp, "-----------------------------------\n");
		solve(fp, wfp);
	}
	fclose(fp);
	fclose(wfp);
	return 0;
}

