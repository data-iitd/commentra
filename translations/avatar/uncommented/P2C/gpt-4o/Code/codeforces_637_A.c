#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    int n;
    scanf("%d\n", &n);
    
    char *s[MAX_WORDS];
    char input[10000];
    fgets(input, sizeof(input), stdin);
    
    // Tokenize the input string
    char *token = strtok(input, " \n");
    int index = 0;
    
    while (token != NULL) {
        s[index] = malloc(strlen(token) + 1);
        strcpy(s[index], token);
        token = strtok(NULL, " \n");
        index++;
    }
    
    // Count occurrences of each word
    WordCount w[MAX_WORDS];
    int unique_count = 0;
    
    for (int i = 0; i < index; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(w[j].word, s[i]) == 0) {
                w[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(w[unique_count].word, s[i]);
            w[unique_count].count = 1;
            unique_count++;
        }
    }
    
    // Find the most frequent word with the latest occurrence
    int max_count = 0;
    char *result = NULL;
    int latest_index = -1;
    
    for (int i = 0; i < unique_count; i++) {
        if (w[i].count > max_count) {
            max_count = w[i].count;
            result = w[i].word;
            latest_index = -1; // Reset latest index
            for (int k = 0; k < index; k++) {
                if (strcmp(s[k], result) == 0) {
                    latest_index = k; // Update latest index
                }
            }
        } else if (w[i].count == max_count) {
            int current_index = -1;
            for (int k = 0; k < index; k++) {
                if (strcmp(s[k], w[i].word) == 0) {
                    current_index = k; // Get current index
                }
            }
            if (current_index > latest_index) {
                result = w[i].word;
                latest_index = current_index;
            }
        }
    }
    
    printf("%s\n", result);
    
    // Free allocated memory
    for (int i = 0; i < index; i++) {
        free(s[i]);
    }
    
    return 0;
}

// <END-OF-CODE>
