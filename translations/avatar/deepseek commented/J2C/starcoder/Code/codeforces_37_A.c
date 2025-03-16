
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility class to read input efficiently
typedef struct {
    char *buffer;
    size_t length;
    size_t index;
} FastScanner;

// Utility function to read a new-line terminated line from stdin and put it into buffer
// Returns 1 on success, 0 on failure
int readLine(FastScanner *scanner) {
    int c;
    size_t len = 0;
    while (1) {
        c = getchar();
        if (c == EOF) {
            if (len == 0) {
                return 0;
            }
            break;
        }
        if (c == '\n') {
            break;
        }
        scanner->buffer[len++] = c;
    }
    scanner->buffer[len] = '\0';
    scanner->length = len;
    scanner->index = 0;
    return 1;
}

// Utility function to read a token from stdin and put it into buffer
// Returns 1 on success, 0 on failure
int readToken(FastScanner *scanner) {
    int c;
    size_t len = 0;
    while (1) {
        c = getchar();
        if (c == EOF) {
            if (len == 0) {
                return 0;
            }
            break;
        }
        if (c =='' || c == '\n' || c == '\t') {
            if (len == 0) {
                continue;
            }
            break;
        }
        scanner->buffer[len++] = c;
    }
    scanner->buffer[len] = '\0';
    scanner->length = len;
    scanner->index = 0;
    return 1;
}

// Utility function to read a single integer from stdin
// Returns 1 on success, 0 on failure
int readInt(FastScanner *scanner) {
    int result = 0;
    int c;
    if (!readToken(scanner)) {
        return 0;
    }
    while (1) {
        c = scanner->buffer[scanner->index++];
        if (c < '0' || c > '9') {
            break;
        }
        result = result * 10 + (c - '0');
    }
    return result;
}

int main() {
    FastScanner scanner;
    scanner.buffer = (char *) malloc(10000);
    int n;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int max = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        if (val > max) {
            max = val;
            count = 1;
        } else if (val == max) {
            count++;
        }
    }
    printf("%d %d\n", max, count);
    return 0;
}

