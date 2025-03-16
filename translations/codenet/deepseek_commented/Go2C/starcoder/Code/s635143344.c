#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// Step 3: Create a slice of integers with a length of 3
	int in[3];
	
	// Step 4: Prompt the user to input three integers
	scanf("%d %d %d", &in[0], &in[1], &in[2]);
	
	// Step 5: Sort the slice of integers in ascending order
	qsort(in, 3, sizeof(int), compare);
	
	// Step 6: Perform a calculation using the sorted integers and print the result
	printf("%d\n", in[2]*10 + in[1] + in[0]);
}

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

