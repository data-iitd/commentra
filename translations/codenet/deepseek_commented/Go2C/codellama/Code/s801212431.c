#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

char *next() {
    static char *buf = NULL;
    static size_t buf_size = 0;
    static size_t word_start = 0;
    static size_t word_end = 0;

    if (buf == NULL) {
        buf = malloc(INITIAL_BUF_SIZE);
        buf_size = INITIAL_BUF_SIZE;
    }

    while (1) {
        if (word_end == buf_size) {
            buf_size *= 2;
            buf = realloc(buf, buf_size);
        }

        int c = getchar();
        if (c == EOF) {
            return NULL;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_start == word_end) {
                continue;
            }

            buf[word_end] = '\0';
            char *word = malloc(word_end - word_start + 1);
            strncpy(word, buf + word_start, word_end - word_start);
            word_start = word_end + 1;
            return word;
        }

        buf[word_end++] = c;
    }
}

int min(int x, int y) {
    if (x > y) {
        return y;
    } else {
        return x;
    }
}

int main() {
    char *S = next();

    // Initialize counters for '0's and '1's
    int l0 = 0, l1 = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '0') {
            l0++;
        } else {
            l1++;
        }
    }
    printf("%d\n", 2 * min(l0, l1));

    return 0;
}

