
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function main is the entry point of the program
int main()
{
	// Initialize an empty string variable 's' to store the input DNA sequence
	char *s = "";

	// Read the input DNA sequence from the standard input using scanf() function
	scanf("%s", s);

	// Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
	// and a slice 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
	int count = 0;
	int *counter = NULL;

	// Check if the input DNA sequence is empty or not
	if (strcmp(s, "") == 0)
	{
		// If the input DNA sequence is empty, return without doing anything
		return 0;
	}

	// Initialize the first element of the 'counter' slice with an initial count of 0
	counter = (int *)malloc(sizeof(int));
	counter[0] = 0;

	// Split the input DNA sequence into a slice 'li' of individual nucleotides using strtok() function
	char *li = strtok(s, "");

	// Iterate through each nucleotide in the 'li' slice using a for loop
	for (int i = 0; li != NULL; i++)
	{
		// Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
		if (strcmp(li, "A") == 0 || strcmp(li, "C") == 0 || strcmp(li, "G") == 0 || strcmp(li, "T") == 0)
		{
			// If the current nucleotide is a valid nucleotide, increment the 'count' variable
			count++;
		}
		else
		{
			// If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' slice and reset the 'count' variable to 0
			counter = (int *)realloc(counter, (i + 1) * sizeof(int));
			counter[i] = count;
			count = 0;
		}

		// Get the next nucleotide in the 'li' slice
		li = strtok(NULL, "");
	}

	// Append the final count of nucleotides in the last sub-sequence to the 'counter' slice
	counter = (int *)realloc(counter, (i + 1) * sizeof(int));
	counter[i] = count;

	// Sort the 'counter' slice in ascending order using qsort() function
	qsort(counter, i + 1, sizeof(int), compare);

	// Print the last element of the sorted 'counter' slice, which represents the maximum count of nucleotides in any sub-sequence
	printf("%d\n", counter[i]);

	// Free the memory allocated for the 'counter' slice
	free(counter);

	// Return 0 to indicate that the program executed successfully
	return 0;
}

// Function compare is used to compare two integers in the 'counter' slice
int compare(const void *a, const void *b)
{
	// Cast the 'a' and 'b' pointers to int pointers
	int *ia = (int *)a;
	int *ib = (int *)b;

	// Compare the two integers and return the difference between them
	return *ia - *ib;
}

