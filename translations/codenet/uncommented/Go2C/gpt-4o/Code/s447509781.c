#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} Input;

void initInput(Input *input) {
    input->capacity = 1000000;
    input->buffer = (char *)malloc(input->capacity);
    input->size = 0;
}

void freeInput(Input *input) {
    free(input->buffer);
}

void readLine(Input *input) {
    fgets(input->buffer, input->capacity, stdin);
    input->size = strlen(input->buffer);
    if (input->buffer[input->size - 1] == '\n') {
        input->buffer[input->size - 1] = '\0'; // Remove newline character
    }
}

int nextInt(Input *input) {
    readLine(input);
    return atoi(input->buffer);
}

int64_t* nextIntArray(Input *input, int *length) {
    readLine(input);
    char *token = strtok(input->buffer, " ");
    int capacity = 10;
    int64_t *array = (int64_t *)malloc(capacity * sizeof(int64_t));
    *length = 0;

    while (token != NULL) {
        if (*length >= capacity) {
            capacity *= 2;
            array = (int64_t *)realloc(array, capacity * sizeof(int64_t));
        }
        array[(*length)++] = atoll(token);
        token = strtok(NULL, " ");
    }
    return array;
}

int main() {
    Input input;
    initInput(&input);

    int n = nextInt(&input);
    int length;
    int64_t *s = nextIntArray(&input, &length);
    bool *u = (bool *)calloc(n, sizeof(bool));
    int64_t m = 0, f;

    for (int c = 1; c < n - 1; c++) {
        f = 0;
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true;
            if (u[n - 1 - k * c]) break;
            f += s[n - 1 - k * c] + s[k * c];
            if (m < f) m = f;
        }
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }

    printf("%lld\n", m);

    freeInput(&input);
    free(s);
    free(u);
    return 0;
}

// <END-OF-CODE>
