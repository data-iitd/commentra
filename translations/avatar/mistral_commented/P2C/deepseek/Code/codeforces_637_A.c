#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100000
#define MAX_STRING_LENGTH 100

int main() {
    int n;
    char *input_buffer = (char *)malloc(MAX_STRINGS * MAX_STRING_LENGTH * sizeof(char));
    char *token;
    char *strings[MAX_STRINGS];
    int counts[MAX_STRINGS] = {0};
    int max_count = 0;
    char *longest_string = NULL;
    int longest_index = -1;

    // Read the number of strings
    scanf("%d", &n);
    getchar(); // Consume the newline character after the number

    // Read the strings
    fgets(input_buffer, MAX_STRINGS * MAX_STRING_LENGTH, stdin);
    token = strtok(input_buffer, " ");
    int index = 0;
    while (token != NULL) {
        strings[index] = token;
        counts[index] = 1;
        for (int i = 0; i < index; i++) {
            if (strcmp(strings[i], token) == 0) {
                counts[i]++;
                break;
            }
        }
        if (counts[index] > max_count) {
            max_count = counts[index];
            longest_string = strings[index];
            longest_index = index;
        }
        token = strtok(NULL, " ");
        index++;
    }

    // Print the longest string
    printf("%s\n", longest_string);

    // Free allocated memory
    free(input_buffer);

    return 0;
}
