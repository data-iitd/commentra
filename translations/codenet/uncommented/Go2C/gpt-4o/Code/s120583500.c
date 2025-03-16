#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char s[100001]; // Assuming the input string will not exceed 100000 characters
    scanf("%s", s);

    int count = 0;
    int *counter = malloc(sizeof(int) * (strlen(s) + 1)); // Allocate memory for counter
    int index = 0;

    if (s[0] == '\0') {
        free(counter);
        return 0;
    }

    counter[index++] = 0; // Initialize the first element

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            count++;
        } else {
            counter[index++] = count;
            count = 0;
        }
    }

    counter[index++] = count; // Append the last count

    qsort(counter, index, sizeof(int), compare); // Sort the counter array
    printf("%d\n", counter[index - 1]); // Print the maximum count

    free(counter); // Free allocated memory
    return 0;
}
