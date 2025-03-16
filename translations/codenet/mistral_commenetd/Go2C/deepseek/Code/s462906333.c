#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e14

typedef struct {
    FILE *file;
    char *buffer;
    size_t buffer_size;
    size_t position;
} Scanner;

Scanner* newScanner() {
    Scanner *scanner = (Scanner*)malloc(sizeof(Scanner));
    scanner->file = stdin;
    scanner->buffer = NULL;
    scanner->buffer_size = 0;
    scanner->position = 0;
    return scanner;
}

void pre(Scanner *scanner) {
    if (scanner->position >= scanner->buffer_size) {
        size_t new_size = 10000;
        scanner->buffer = (char*)realloc(scanner->buffer, new_size);
        scanner->buffer_size = new_size;
        size_t bytes_read = fread(scanner->buffer, 1, new_size, scanner->file);
        if (bytes_read < new_size) {
            scanner->buffer_size = bytes_read;
        }
    }
}

void readLine(Scanner *scanner) {
    scanner->position = 0;
    size_t new_size = 10000;
    scanner->buffer = (char*)realloc(scanner->buffer, new_size);
    scanner->buffer_size = new_size;
    size_t bytes_read = fread(scanner->buffer, 1, new_size, scanner->file);
    if (bytes_read < new_size) {
        scanner->buffer_size = bytes_read;
    }
}

char nextChar(Scanner *scanner) {
    pre(scanner);
    return scanner->buffer[scanner->position++];
}

char* next() {
    char *result = (char*)malloc(100);
    int i = 0;
    char c;
    while ((c = nextChar(scanner)) != ' ' && c != '\n') {
        result[i++] = c;
    }
    result[i] = '\0';
    return result;
}

int nextInt(Scanner *scanner) {
    char *str = next();
    int result = atoi(str);
    free(str);
    return result;
}

long long nextInt64(Scanner *scanner) {
    char *str = next();
    long long result = atoll(str);
    free(str);
    return result;
}

int main() {
    Scanner *scanner = newScanner();

    int n = nextInt(scanner);
    int x = nextInt(scanner);

    int a[n];
    int v[n];
    memcpy(v, a, n * sizeof(int));

    long long ans = INF;

    for (int k = 0; k < n; k++) {
        int kans = 0;

        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = (v[i] < a[n + i - k]) ? v[i] : a[n + i - k];
            } else {
                v[i] = (v[i] < a[i - k]) ? v[i] : a[i - k];
            }

            kans += v[i];
        }

        ans = (ans < kans + k * x) ? ans : kans + k * x;
    }

    printf("%lld\n", ans);

    free(scanner->buffer);
    free(scanner);
    return 0;
}

