#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000000

//  長い入力を読む
int read_long_lines(int times, char *result[]) {
	int i;
	char *line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
	for (i = 0; i < times; i++) {
		fgets(line, MAX_LINE_LENGTH, stdin);
		result[i] = (char *)malloc((strlen(line) + 1) * sizeof(char));
		strcpy(result[i], line);
	}
	free(line);
	return 0;
}

// 出力 for 競プロ
typedef struct {
	FILE *fp;
} Console;

Console NewConsole() {
	Console con;
	con.fp = stdout;
	return con;
}
void Printf(Console con, char *format, ...) {
	va_list args;
	va_start(args, format);
	vfprintf(con.fp, format, args);
	va_end(args);
}
void Println(Console con, char *s) {
	fprintf(con.fp, "%s\n", s);
}
void Close(Console con) {
	fflush(con.fp);
}

void PrintList(int *list, int size) {
	Console con = NewConsole();
	int i;
	for (i = 0; i < size; i++) {
		if (i == 0) {
			Printf(con, "%d", list[i]);
		} else {
			Printf(con, " %d", list[i]);
		}
	}
	Println(con, "");
	Close(con);
}

int main() {
	Console con = NewConsole();
	int *result = (int *)malloc(200000 * sizeof(int));
	int i, j;
	int *a = (int *)malloc(200000 * sizeof(int));
	int *b = (int *)malloc(200000 * sizeof(int));
	int *m = (int *)malloc(200000 * sizeof(int));
	int size = 0;
	char **lines = (char **)malloc(4 * sizeof(char *));
	read_long_lines(4, lines);
	for (i = 0; i < 200000; i++) {
		m[i] = 0;
	}
	for (i = 0; i < 200000; i++) {
		sscanf(lines[1], "%d", &a[i]);
		lines[1] += strlen(lines[1]) + 1;
	}
	for (i = 0; i < 200000; i++) {
		sscanf(lines[3], "%d", &b[i]);
		lines[3] += strlen(lines[3]) + 1;
	}
	for (i = 0; i < 200000; i++) {
		if (m[a[i]] == 0) {
			m[a[i]] = 1;
			size++;
		}
	}
	for (i = 0; i < 200000; i++) {
		if (m[b[i]] == 0) {
			m[b[i]] = 1;
			size++;
		} else {
			m[b[i]] = 0;
		}
	}
	for (i = 0; i < 200000; i++) {
		if (m[i] == 1) {
			result[i] = i;
		}
	}
	qsort(result, size, sizeof(int), cmp);
	for (j = 0; j < size; j++) {
		Printf(con, "%d\n", result[j]);
	}
	Println(con, "");
	Close(con);
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

