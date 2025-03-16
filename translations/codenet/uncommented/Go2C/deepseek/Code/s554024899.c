#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct {
    FILE *file;
    char *buffer;
    size_t buffer_size;
    size_t buffer_index;
} Scanner;

Scanner* newScanner() {
    Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
    scanner->file = stdin;
    scanner->buffer = (char *)malloc(1000);
    scanner->buffer_size = 1000;
    scanner->buffer_index = 0;
    return scanner;
}

void readLine(Scanner *scanner) {
    size_t len = 0;
    ssize_t read;
    if (scanner->buffer_index < scanner->buffer_size) {
        scanner->buffer[scanner->buffer_index] = '\0';
        return;
    }
    read = getline(&(scanner->buffer), &len, scanner->file);
    if (read == -1) {
        scanner->buffer[0] = '\0';
    }
}

char* next(Scanner *scanner) {
    while (scanner->buffer_index < strlen(scanner->buffer) && scanner->buffer[scanner->buffer_index] == ' ') {
        scanner->buffer_index++;
    }
    if (scanner->buffer_index >= strlen(scanner->buffer)) {
        readLine(scanner);
        scanner->buffer_index = 0;
    }
    size_t start = scanner->buffer_index;
    while (scanner->buffer_index < strlen(scanner->buffer) && scanner->buffer[scanner->buffer_index] != ' ') {
        scanner->buffer_index++;
    }
    char *result = (char *)malloc(scanner->buffer_index - start + 1);
    strncpy(result, scanner->buffer + start, scanner->buffer_index - start);
    result[scanner->buffer_index - start] = '\0';
    return result;
}

int nextInt(Scanner *scanner) {
    char *str = next(scanner);
    int value = atoi(str);
    free(str);
    return value;
}

int main() {
    Scanner *scanner = newScanner();
    int x = nextInt(scanner);
    int y = nextInt(scanner);
    int xt = -1, yt = -1;
    int a[3][3] = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11},
        {2}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); j++) {
            if (x == a[i][j]) {
                xt = i;
            }
            if (y == a[i][j]) {
                yt = i;
            }
        }
    }
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(scanner->buffer);
    free(scanner);
    return 0;
}
