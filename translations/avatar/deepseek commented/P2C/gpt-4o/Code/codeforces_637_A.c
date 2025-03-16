#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    char str[MAX_STRING_LENGTH];
    int count;
} Counter;

int main() {
    int n;
    scanf("%d\n", &n);
    
    char s[MAX_STRINGS][MAX_STRING_LENGTH];
    Counter w[MAX_STRINGS];
    int w_size = 0;

    // Read the strings
    for (int i = 0; i < n; i++) {
        fgets(s[i], MAX_STRING_LENGTH, stdin);
        s[i][strcspn(s[i], "\n")] = 0; // Remove newline character
    }

    // Count occurrences of each string
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < w_size; j++) {
            if (strcmp(s[i], w[j].str) == 0) {
                w[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(w[w_size].str, s[i]);
            w[w_size].count = 1;
            w_size++;
        }
    }

    // Find the maximum count
    int max_count = 0;
    for (int i = 0; i < w_size; i++) {
        if (w[i].count > max_count) {
            max_count = w[i].count;
        }
    }

    // Find the last string with the maximum count
    char result[MAX_STRING_LENGTH];
    int last_index = -1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < w_size; j++) {
            if (strcmp(s[i], w[j].str) == 0 && w[j].count == max_count) {
                if (i > last_index) {
                    strcpy(result, s[i]);
                    last_index = i;
                }
            }
        }
    }

    // Print the result
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
