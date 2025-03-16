#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define INF 1e8
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

typedef struct {
    int index;
    int p1, p2;
} Pair;

typedef struct {
    Pair *data;
    int size;
} Pairs;

typedef struct {
    int *data;
    int size;
} Int64Slice;

typedef struct {
    char **data;
    int size;
} Strings;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

double readFloat() {
    double value;
    scanf("%lf", &value);
    return value;
}

void write(const char *s) {
    printf("%s", s);
}

void print() {
    fflush(stdout);
}

int s2i(const char *s) {
    return atoi(s);
}

char *i2s(int i) {
    char *buffer = (char *)malloc(12 * sizeof(char));
    sprintf(buffer, "%d", i);
    return buffer;
}

double s2f(const char *s) {
    return atof(s);
}

int abs(int i) {
    return abs(i);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int sum(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void split(const char *s, char **tokens, int *tokenCount) {
    char *copy = strdup(s);
    *tokenCount = 0;
    char *token = strtok(copy, " ");
    while (token != NULL) {
        tokens[*tokenCount] = token;
        (*tokenCount)++;
        token = strtok(NULL, " ");
    }
    free(copy);
}

int *strAry2intAry(const char **strs, int size) {
    int *ret = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        ret[i] = s2i(strs[i]);
    }
    return ret;
}

char **intAry2strAry(const int *nums, int size) {
    char **ret = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        ret[i] = i2s(nums[i]);
    }
    return ret;
}

char *ary2str(const char **strs, int size) {
    char *result = (char *)malloc(100 * size * sizeof(char));
    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            result[pos++] = ' ';
        }
        strcpy(result + pos, strs[i]);
        pos += strlen(strs[i]);
    }
    result[pos] = '\0';
    return result;
}

void reverse(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void reverseStr(char **arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        char *temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void ini(int *arr, int size, int init) {
    for (int i = 0; i < size; i++) {
        arr[i] = init;
    }
}

