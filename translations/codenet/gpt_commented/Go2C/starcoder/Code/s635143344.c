


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
	int in[3];
	scanf("%d %d %d", &in[0], &in[1], &in[2]);
	qsort(in, 3, sizeof(int), compare);
	printf("%d", in[2]*10 + in[1] + in[0]);
	return 0;
}

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

