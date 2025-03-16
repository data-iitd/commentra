#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} FastScanner;

FastScanner* createFastScanner(int capacity) {
    FastScanner* scanner = (FastScanner*)malloc(sizeof(FastScanner));
    scanner->data = (int*)malloc(capacity * sizeof(int));
    scanner->size = 0;
    scanner->capacity = capacity;
    return scanner;
}

void addNumber(FastScanner* scanner, int number) {
    if (scanner->size == scanner->capacity) {
        scanner->capacity *= 2;
        scanner->data = (int*)realloc(scanner->data, scanner->capacity * sizeof(int));
    }
    scanner->data[scanner->size++] = number;
}

int main() {
    int n;
    scanf("%d", &n);
    FastScanner* scanner = createFastScanner(n);
    int map[100001] = {0};
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        map[val]++;
        addNumber(scanner, val);
    }
    int max = 0;
    for (int i = 0; i < scanner->size; i++) {
        int val = map[scanner->data[i]];
        if (val > max) {
            max = val;
        }
    }
    printf("%d %lu\n", max, scanner->size);
    free(scanner->data);
    free(scanner);
    return 0;
}
