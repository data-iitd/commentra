

#include <stdio.h>
#include <stdlib.h>

int main() {
	int ns[4]; // Declare an array of integers with a length of 4
	if (scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]) == 4) { // Read four integers from standard input and store them in the array ns
		qsort(ns, 4, sizeof(int), compare); // Sort the array ns in ascending order using the qsort function
		if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) { // Check if the sorted array ns contains the numbers 1, 4, 7, and 9 in that order
			printf("YES\n"); // Print "YES" if the condition is true
		} else {
			printf("NO\n"); // Print "NO" if the condition is false
		}
	}
	return 0;
}

int compare(const void *a, const void *b) { // Function to compare two integers for sorting
	int x = *(int*)a;
	int y = *(int*)b;
	return (x - y);
}

