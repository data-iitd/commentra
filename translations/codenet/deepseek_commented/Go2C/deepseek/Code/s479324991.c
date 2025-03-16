#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
    size_t pos;
} Scanner;

Scanner* newScanner() {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->buf = NULL;
    s->len = 0;
    s->pos = 0;
    return s;
}

void readLine(Scanner *s) {
    s->len = 0;
    s->buf = (char*)malloc(1000);
    fgets(s->buf, 1000, stdin);
}

char* next(Scanner *s) {
    while (s->pos < s->len && s->buf[s->pos] != ' ' && s->buf[s->pos] != '\n') {
        s->pos++;
    }
    char *token = (char*)malloc(s->pos - s->pos + 1);
    strncpy(token, s->buf, s->pos);
    token[s->pos] = '\0';
    s->pos++;
    return token;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int value = atoi(token);
    free(token);
    return value;
}

int* nextIntArray(Scanner *s, int *size) {
    readLine(s);
    s->pos = 0;
    int count = 0;
    for (int i = 0; i < s->len; i++) {
        if (s->buf[i] == ' ') {
            count++;
        }
    }
    count++;
    int *arr = (int*)malloc(count * sizeof(int));
    int index = 0;
    char *start = s->buf;
    for (int i = 0; i < s->len; i++) {
        if (s->buf[i] == ' ' || s->buf[i] == '\n') {
            s->buf[i] = '\0';
            arr[index++] = atoi(start);
            start = &s->buf[i + 1];
        }
    }
    *size = count;
    free(s->buf);
    return arr;
}

void sortFloatArray(float *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float calculateAverage(float *arr, int size) {
    float prev = arr[0];
    for (int i = 1; i < size; i++) {
        prev = (prev + arr[i]) / 2;
    }
    return prev;
}

int main() {
    Scanner *sc = newScanner();
    int n = nextInt(sc);
    float *arr = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt(sc);
    }
    sortFloatArray(arr, n);
    float result = calculateAverage(arr, n);
    printf("%f\n", result);
    free(arr);
    free(sc);
    return 0;
}
