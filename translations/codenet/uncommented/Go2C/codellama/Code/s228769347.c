#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAX_BUFFER_SIZE 500001

typedef struct {
	int *data;
	int size;
	int capacity;
} IntArray;

IntArray *createIntArray(int capacity) {
	IntArray *array = (IntArray *)malloc(sizeof(IntArray));
	array->data = (int *)malloc(sizeof(int) * capacity);
	array->size = 0;
	array->capacity = capacity;
	return array;
}

void addIntArray(IntArray *array, int value) {
	if (array->size == array->capacity) {
		array->capacity *= 2;
		array->data = (int *)realloc(array->data, sizeof(int) * array->capacity);
	}
	array->data[array->size++] = value;
}

void sortIntArray(IntArray *array) {
	qsort(array->data, array->size, sizeof(int), compareInt);
}

int compareInt(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int getNextInt(FILE *fp) {
	char buffer[MAX_BUFFER_SIZE];
	char *p = fgets(buffer, MAX_BUFFER_SIZE, fp);
	if (p == NULL) {
		return -1;
	}
	return atoi(p);
}

int main(int argc, char *argv[]) {
	FILE *fp = stdin;
	FILE *wfp = stdout;

	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	IntArray *array = createIntArray(100000);
	int n = getNextInt(fp);
	for (int i = 0; i < n; i++) {
		addIntArray(array, getNextInt(fp));
	}
	sortIntArray(array);

	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int l = j + 1;
			int r = n;
			while (l < r) {
				int m = (l + r) / 2;
				if (array->data[m] < array->data[i] + array->data[j]) {
					l = m + 1;
					continue;
				}
				r = m;
			}
			ans += l - (j + 1);
		}
	}
	fprintf(wfp, "%d\n", ans);

	fclose(fp);
	fclose(wfp);
	return 0;
}

