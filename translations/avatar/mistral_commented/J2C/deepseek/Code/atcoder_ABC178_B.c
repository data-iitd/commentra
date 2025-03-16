#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} StringBuilder;

StringBuilder* createStringBuilder() {
    StringBuilder* sb = (StringBuilder*)malloc(sizeof(StringBuilder));
    sb->data = (char*)malloc(1);
    sb->data[0] = '\0';
    sb->size = 0;
    sb->capacity = 1;
    return sb;
}

void append(StringBuilder* sb, const char* str) {
    size_t len = strlen(str);
    while (sb->size + len >= sb->capacity) {
        sb->capacity *= 2;
        sb->data = (char*)realloc(sb->data, sb->capacity);
    }
    strcpy(sb->data + sb->size, str);
    sb->size += len;
}

void freeStringBuilder(StringBuilder* sb) {
    free(sb->data);
    free(sb);
}

int modPower(int x, int y, int mod) {
    int res = 1;
    x %= mod;

    if (x == 0) return 0;

    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

typedef struct {
    int first;
    int second;
} Pair;

Pair createPair(int first, int second) {
    Pair p;
    p.first = first;
    p.second = second;
    return p;
}

int main() {
    StringBuilder* input = createStringBuilder();
    char c;
    while ((c = getchar()) != EOF && c != '\n') {
        append(input, &c);
    }

    long a[4];
    char* token = strtok(input->data, " ");
    int i = 0;
    while (token != NULL) {
        a[i++] = atol(token);
        token = strtok(NULL, " ");
    }

    long result = a[0] * a[2] > a[1] * a[3] ? (a[0] * a[2] > a[0] * a[3] ? (a[0] * a[2] > a[1] * a[2] ? a[0] * a[2] : a[1] * a[2]) : (a[0] * a[3] > a[1] * a[2] ? a[0] * a[3] : a[1] * a[2])) : (a[1] * a[3] > a[0] * a[3] ? (a[1] * a[3] > a[1] * a[2] ? a[1] * a[3] : a[1] * a[2]) : (a[0] * a[3] > a[1] * a[2] ? a[0] * a[3] : a[1] * a[2]));

    printf("%ld\n", result);

    freeStringBuilder(input);
    return 0;
}
