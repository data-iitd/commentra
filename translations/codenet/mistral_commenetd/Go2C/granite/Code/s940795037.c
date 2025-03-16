
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
    return s;
}

char *next(Scanner *s) {
    // Preprocessing the input buffer
    if (s->p >= strlen(s->buf)) {
        s->p = 0;
        fgets(s->buf, 1000, stdin);
    }
    // Reading the next token from the input buffer
    int start = s->p;
    while (s->p < strlen(s->buf) && s->buf[s->p]!='') {
        s->p++;
    }
    // Reading the token from the input buffer
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    // Incrementing the position of the input buffer pointer
    s->p++;
    // Returning the token
    return result;
}

char *nextLine(Scanner *s) {
    // Preprocessing the input buffer
    if (s->p >= strlen(s->buf)) {
        s->p = 0;
        fgets(s->buf, 1000, stdin);
    }
    // Reading the next line from the input buffer
    int start = s->p;
    s->p = strlen(s->buf);
    // Reading the rest of the line if available
    fgets(s->buf + s->p, 1000 - s->p, stdin);
    // Creating a slice from the current position to the end of the input buffer
    char *result = (char *)malloc((strlen(s->buf) - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, strlen(s->buf) - start);
    result[strlen(s->buf) - start] = '\0';
    // Returning the line
    return result;
}

int nextInt(Scanner *s) {
    // Reading the next token as a string
    char *token = next(s);
    // Converting the token to an integer
    int v = atoi(token);
    // Returning the integer
    return v;
}

int *nextIntArray(Scanner *s) {
    // Reading the next token as a string
    char *token = next(s);
    // Initializing an empty slice
    int *result = (int *)malloc(100 * sizeof(int));
    int size = 0;
    // Reading each integer from the standard input and appending it to the slice
    while (token[0] >= '0' && token[0] <= '9') {
        int v = atoi(token);
        result[size] = v;
        size++;
        // Reading the next token
        token = next(s);
        // If the current token is not a space character, then there is an error in the input
        if (token[0]!='') {
            printf("Invalid input");
            exit(1);
        }
    }
    // Returning the slice
    return result;
}

int main() {
    Scanner *s = newScanner();
    int n = nextInt(s);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = 1 / nextInt(s);
        ans += tmp;
    }
    printf("%f\n", 1 / ans);
    return 0;
}

// END-OF-CODE