#include <stdio.h> // Include the standard input-output library for scanf and printf
#include <stdlib.h> // Include the standard library for the sort function
#include <string.h> // Include the standard library for the strlen function

int main(void)
{
	int *a, *b, i, N; // Declare pointers to integers, a loop variable, and the number of elements
	int frontHalf, backHalf; // Declare two integers to hold the two halves

	scanf("%d", &N); // Read the number of elements from the user
	a = (int *)malloc(N * sizeof(int)); // Dynamically allocate memory for array a
	b = (int *)malloc(N * sizeof(int)); // Dynamically allocate memory for array b

	for (i = 0; i < N; i++) // Loop to read elements into array a and copy them to array b
	{
		scanf("%d", a + i); // Read an element into array a
		b[i] = a[i]; // Copy the element from array a to array b
	}

	qsort(b, N, sizeof(int), compare); // Sort array b

	frontHalf = b[N / 2 - 1]; // Calculate the first half's middle value
	backHalf = b[N / 2]; // Calculate the second half's middle value

	free(b); // Free the dynamically allocated memory for array b

	for (i = 0; i < N; i++) // Loop to compare each element of array a
	{
		if (a[i] < backHalf) // Check if the element is less than the second middle value
			printf("%d\n", backHalf); // Print the second middle value
		else
			printf("%d\n", frontHalf); // Print the first middle value
	}

	free(a); // Free the dynamically allocated memory for array a
	return 0; // Return 0 to indicate successful execution
}

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

