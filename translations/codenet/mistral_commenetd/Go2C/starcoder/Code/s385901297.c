
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main(int argc, char *argv[]) {
	// Initialize a new scanner to read input from standard input
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	int ns[4];

	printf("Reading input\n");
	read = getline(&line, &len, stdin);
	assert(read!= -1);
	token = strtok(line, " ");
	sscanf(token, "%d", &ns[0]);
	token = strtok(NULL, " ");
	sscanf(token, "%d", &ns[1]);
	token = strtok(NULL, " ");
	sscanf(token, "%d", &ns[2]);
	token = strtok(NULL, " ");
	sscanf(token, "%d", &ns[3]);

	// Sort the ns slice in ascending order
	printf("Sorting the numbers in ns slice\n");
	qsort(ns, 4, sizeof(int), compare);

	// Check if the sorted ns slice matches the specific condition (1, 4, 7, 9)
	printf("Checking the condition\n");
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		printf("The condition is true, print YES\n");
		printf("Output: YES\n");
		printf("\n");
		printf("End of the program\n");
		return 0;
	} else {
		printf("The condition is false, print NO\n");
		printf("Output: NO\n");
		printf("\n");
		printf("End of the program\n");
		return 0;
	}
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

