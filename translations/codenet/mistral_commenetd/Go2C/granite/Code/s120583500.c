

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize an empty string variable's' to store the input DNA sequence
    char s[1000];

    // Read the input DNA sequence from the standard input using scanf() function
    scanf("%s", s);

    // Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
    // and a slice 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
    int count = 0;
    int *counter = (int *)malloc(sizeof(int));

    // Check if the input DNA sequence is empty or not
    if (strlen(s) == 0) {
        // If the input DNA sequence is empty, return without doing anything
        return 0;
    }

    // Initialize the first element of the 'counter' slice with an initial count of 0
    counter[0] = 0;

    // Split the input DNA sequence into a slice 'li' of individual nucleotides using strsplit() function
    char **li = strsplit(s, "");

    // Iterate through each nucleotide in the 'li' slice using a for loop
    for (int i = 0; li[i]!= NULL; i++) {
        // Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
        if (strcmp(li[i], "A") == 0 || strcmp(li[i], "C") == 0 || strcmp(li[i], "G") == 0 || strcmp(li[i], "T") == 0) {
            // If the current nucleotide is a valid nucleotide, increment the 'count' variable
            count++;
        } else {
            // If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' slice and reset the 'count' variable to 0
            counter = (int *)realloc(counter, (sizeof(int) * (i + 2)));
            counter[i + 1] = count;
            count = 0;
        }
    }

    // Append the final count of nucleotides in the last sub-sequence to the 'counter' slice
    counter = (int *)realloc(counter, (sizeof(int) * (i + 2)));
    counter[i + 1] = count;

    // Sort the 'counter' slice in ascending order using qsort() function
    qsort(counter, i + 2, sizeof(int), compare);

    // Print the last element of the sorted 'counter' slice, which represents the maximum count of nucleotides in any sub-sequence
    printf("%d\n", counter[i]);

    // Free the memory allocated for the 'counter' slice
    free(counter);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

