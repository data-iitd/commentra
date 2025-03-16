
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100]; // Step 1: The program starts by taking a string input from the user.
    scanf("%s", s);

    int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
    int *counter = (int *)malloc(sizeof(int));

    if (strlen(s) == 0) { // Step 3: It checks if the input string is empty and returns immediately if it is.
        return 0;
    }
    *counter = 0; // Step 4: It splits the input string into individual characters.
    char *li[100];
    char *token = strtok(s, " ");
    int i = 0;
    while (token!= NULL) {
        li[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    for (int j = 0; j < i; j++) { // Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
        if (strcmp(li[j], "A") == 0 || strcmp(li[j], "C") == 0 || strcmp(li[j], "G") == 0 || strcmp(li[j], "T") == 0) {
            count++;
        } else {
            counter = (int *)realloc(counter, (sizeof(int) * (i + 1)));
            counter[i] = count;
            count = 0;
        }
    }

    counter = (int *)realloc(counter, (sizeof(int) * (i + 1)));
    counter[i] = count; // Step 6: It appends the final count to the counter array and sorts the array.
    qsort(counter, i + 1, sizeof(int), compare);
    printf("%d\n", counter[i]); // Step 7: Finally, it prints the maximum value in the sorted counter array.

    free(counter);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

