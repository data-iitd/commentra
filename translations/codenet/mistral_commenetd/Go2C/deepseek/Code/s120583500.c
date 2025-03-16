#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];
    int count = 0;
    int counter[1000];
    int counter_index = 0;

    // Read the input DNA sequence from the standard input
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 0;
    }

    // Remove the newline character if present
    s[strcspn(s, "\n")] = '\0';

    // Check if the input DNA sequence is empty or not
    if (strlen(s) == 0) {
        return 0;
    }

    // Initialize the first element of the 'counter' array with an initial count of 0
    counter[counter_index++] = 0;

    // Iterate through each character in the input DNA sequence
    for (int i = 0; i < strlen(s); i++) {
        // Check if the current character is a valid nucleotide (A, C, G, T) or not
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            // If the current character is a valid nucleotide, increment the 'count' variable
            count++;
        } else {
            // If the current character is not a valid nucleotide, append the current count to the 'counter' array and reset the 'count' variable to 0
            counter[counter_index++] = count;
            count = 0;
        }
    }

    // Append the final count of nucleotides in the last sub-sequence to the 'counter' array
    counter[counter_index++] = count;

    // Sort the 'counter' array in ascending order
    for (int i = 0; i < counter_index - 1; i++) {
        for (int j = i + 1; j < counter_index; j++) {
            if (counter[i] > counter[j]) {
                int temp = counter[i];
                counter[i] = counter[j];
                counter[j] = temp;
            }
        }
    }

    // Print the last element of the sorted 'counter' array, which represents the maximum count of nucleotides in any sub-sequence
    printf("%d\n", counter[counter_index - 1]);

    return 0;
}
