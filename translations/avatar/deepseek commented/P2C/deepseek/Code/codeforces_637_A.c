#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[1000000];
    getchar(); // to consume the newline character after the integer input
    fgets(s, 1000000, stdin);

    // Remove the newline character at the end of the string
    s[strcspn(s, "\n")] = 0;

    // Split the string into words
    char *token = strtok(s, " ");
    int word_count = 0;
    char *words[100000];
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    int max_count = 0;
    char *max_word = NULL;
    for (int i = 0; i < word_count; i++) {
        int count = 0;
        for (int j = 0; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_word = words[i];
        }
    }

    // Reverse the array of words
    for (int i = 0; i < word_count / 2; i++) {
        char *temp = words[i];
        words[i] = words[word_count - i - 1];
        words[word_count - i - 1] = temp;
    }

    // Find the first occurrence of the most frequent word in the reversed array
    int c = -1;
    int a = 0;
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i], max_word) == 0) {
            if (i > c) {
                c = i;
                a = i;
            }
        }
    }

    // Print the value of a
    printf("%d\n", a);

    return 0;
}
