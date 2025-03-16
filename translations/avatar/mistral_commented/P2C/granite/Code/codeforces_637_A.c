
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Read the number of strings to be processed
    int n;
    scanf("%d", &n);

    // Read the strings and store them in an array
    char **s = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", s[i]);
    }

    // Create a hash table to store the occurrences of each string
    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        w[i] = 0;
    }

    // Count the occurrences of each string
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(s[i], s[j]) == 0) {
                w[i]++;
            }
        }
    }

    // Find the index of the longest string
    int max_index = 0;
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] > max_count) {
            max_index = i;
            max_count = w[i];
        }
    }

    // Print the longest string
    printf("%s\n", s[max_index]);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(w);

    return 0;
}
