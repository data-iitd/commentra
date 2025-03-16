#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
    size_t pos;
} Scanner;

Scanner* newScanner() {
    Scanner *sc = (Scanner*)malloc(sizeof(Scanner));
    sc->buf = NULL;
    sc->len = 0;
    sc->pos = 0;
    return sc;
}

void readLine(Scanner *sc) {
    if (sc->buf) free(sc->buf);
    sc->len = 0;
    sc->pos = 0;
    sc->buf = (char*)malloc(1000);
    fgets(sc->buf, 1000, stdin);
    if (sc->buf[strlen(sc->buf) - 1] == '\n') {
        sc->buf[strlen(sc->buf) - 1] = '\0';
    }
}

char* next(Scanner *sc) {
    while (sc->pos < strlen(sc->buf) && sc->buf[sc->pos] == ' ') {
        sc->pos++;
    }
    if (sc->pos >= strlen(sc->buf)) {
        return NULL;
    }
    size_t start = sc->pos;
    while (sc->pos < strlen(sc->buf) && sc->buf[sc->pos] != ' ') {
        sc->pos++;
    }
    char *result = (char*)malloc(sc->pos - start + 1);
    strncpy(result, sc->buf + start, sc->pos - start);
    result[sc->pos - start] = '\0';
    return result;
}

char* nextLine(Scanner *sc) {
    readLine(sc);
    return sc->buf;
}

int nextInt(Scanner *sc) {
    char *token = next(sc);
    int result = atoi(token);
    free(token);
    return result;
}

int* nextIntArray(Scanner *sc, int *size) {
    char *line = nextLine(sc);
    int capacity = 10;
    int *result = (int*)malloc(capacity * sizeof(int));
    *size = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        if (*size >= capacity) {
            capacity *= 2;
            result = (int*)realloc(result, capacity * sizeof(int));
        }
        result[*size] = atoi(token);
        (*size)++;
        token = strtok(NULL, " ");
    }
    free(line);
    return result;
}

int main() {
    Scanner *sc = newScanner();
    int n = nextInt(sc);
    float *arr = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        arr[i] = (float)nextInt(sc);
    }

    // Sort the array of float64 values
    qsort(arr, n, sizeof(float), (int (*)(const void *, const void *))compareFloat);

    // Initialize 'prev' with the first element of the sorted array
    float prev = arr[0];

    // Calculate the average of the elements iteratively
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    // Print the final computed average
    printf("%f\n", prev);

    free(arr);
    free(sc->buf);
    free(sc);
    return 0;
}

int compareFloat(const void *a, const void *b) {
    float fa = *(const float *) a;
    float fb = *(const float *) b;
    return (fa > fb) - (fa < fb);
}
