#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LEN 100

typedef struct {
    char word[MAX_LEN];
    int count;
} WordCount;

int main() {
    int n;
    scanf("%d\n", &n);  // Read the number of elements

    char *s[MAX_N];  // Array to hold the words
    WordCount wc[MAX_N];  // Array to hold unique words and their counts
    int unique_count = 0;

    // Read the input string and split it into words
    char input[1000000];
    fgets(input, sizeof(input), stdin);
    
    char *token = strtok(input, " \n");
    while (token != NULL) {
        s[unique_count] = token;  // Store the word
        int found = 0;

        // Check if the word is already counted
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(wc[j].word, token) == 0) {
                wc[j].count++;
                found = 1;
                break;
            }
        }

        // If the word is new, add it to the count array
        if (!found) {
            strcpy(wc[unique_count].word, token);
            wc[unique_count].count = 1;
            unique_count++;
        }

        token = strtok(NULL, " \n");
    }

    // Reverse the list of words
    for (int i = 0; i < unique_count / 2; i++) {
        char *temp = s[i];
        s[i] = s[unique_count - 1 - i];
        s[unique_count - 1 - i] = temp;
    }

    int max_count = 0;
    char *result = NULL;

    // Find the most frequent element that appears last in the original order
    for (int i = 0; i < unique_count; i++) {
        if (wc[i].count > max_count) {
            max_count = wc[i].count;
            result = wc[i].word;
        } else if (wc[i].count == max_count) {
            // Check the index in the reversed list
            for (int j = 0; j < unique_count; j++) {
                if (strcmp(s[j], wc[i].word) == 0) {
                    if (j > (result ? (s - result) : -1)) {
                        result = wc[i].word;
                    }
                    break;
                }
            }
        }
    }

    // Print the most frequent element that appears last in the original order
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
