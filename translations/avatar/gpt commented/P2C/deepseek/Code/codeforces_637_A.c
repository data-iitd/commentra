#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000

// Structure to hold a word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures for qsort
int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc1->count - wc2->count;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // Consume the newline character after the number

    char s[MAX_WORDS];
    fgets(s, MAX_WORDS, stdin);
    s[strcspn(s, "\n")] = '\0';  // Remove the newline character

    char *token = strtok(s, " ");
    WordCount words[MAX_WORDS];
    int word_count = 0;

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[word_count].word = token;
            words[word_count].count = 1;
            word_count++;
        }
        token = strtok(NULL, " ");
    }

    // Sort the words by count
    qsort(words, word_count, sizeof(WordCount), compare);

    // Find the last occurrence of the most frequent word
    char *most_frequent_word = NULL;
    int max_count = 0;
    for (int i = word_count - 1; i >= 0; i--) {
        if (words[i].count > max_count) {
            most_frequent_word = words[i].word;
            max_count = words[i].count;
        }
    }

    // Print the most frequent word that appears last in the original order
    printf("%s\n", most_frequent_word);

    return 0;
}
