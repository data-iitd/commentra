#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to handle input reading efficiently
typedef struct {
    char *buf; // Buffer to hold the input line
    size_t len; // Length of the buffer
    size_t pos; // Current position in the buffer
} Scanner;

// Function prototypes
Scanner* NewScanner();
void Next(Scanner *s);
void NextLine(Scanner *s);
int NextInt(Scanner *s);
int* NextIntArray(Scanner *s, int *size);

// Function to initialize a new Scanner instance
Scanner* NewScanner() {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->len = 1000; // Initial buffer size
    s->buf = (char*)malloc(s->len);
    s->pos = 0;
    return s;
}

// Function to read the next token from the input
void Next(Scanner *s) {
    while (s->pos < s->len && s->buf[s->pos] == ' ') s->pos++;
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    int start = s->pos;
    while (s->pos < s->len && s->buf[s->pos] != ' ') s->pos++;
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    printf("%s\n", strndup(s->buf + start, s->pos - start));
}

// Function to read the next full line from the input
void NextLine(Scanner *s) {
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    printf("%s", strndup(s->buf + s->pos, s->len - s->pos));
    s->pos = s->len;
}

// Function to read the next integer from the input
int NextInt(Scanner *s) {
    char *end;
    while (s->pos < s->len && s->buf[s->pos] == ' ') s->pos++;
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    int start = s->pos;
    while (s->pos < s->len && s->buf[s->pos] != ' ' && s->buf[s->pos] != '\n') s->pos++;
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    int result = strtol(s->buf + start, &end, 10);
    return result;
}

// Function to read a space-separated array of integers from the input
int* NextIntArray(Scanner *s, int *size) {
    while (s->pos < s->len && s->buf[s->pos] == ' ') s->pos++;
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    int start = s->pos;
    int count = 0;
    while (s->pos < s->len && s->buf[s->pos] != ' ' && s->buf[s->pos] != '\n') {
        s->pos++;
        count++;
    }
    if (s->pos >= s->len) {
        fgets(s->buf, (int)s->len, stdin);
        s->pos = 0;
    }
    int *result = (int*)malloc(count * sizeof(int));
    char *token = strndup(s->buf + start, s->pos - start);
    char *saveptr;
    int index = 0;
    char *token2 = strtok_r(token, " ", &saveptr);
    while (token2 != NULL) {
        result[index++] = strtol(token2, NULL, 10);
        token2 = strtok_r(NULL, " ", &saveptr);
    }
    free(token);
    *size = count;
    return result;
}

// Main function where the execution starts
int main() {
    // Create a new scanner to read input
    Scanner *sc = NewScanner();

    // Read the number of integers to process
    int n = NextInt(sc);
    double ans = 0.0;

    // Loop through each integer, calculate the reciprocal, and accumulate the sum
    for (int i = 0; i < n; i++) {
        int tmp = NextInt(sc);
        ans += 1.0 / tmp;
    }

    // Print the harmonic mean of the input integers
    printf("%f\n", 1.0 / ans);

    // Free allocated memory
    free(sc->buf);
    free(sc);

    return 0;
}
