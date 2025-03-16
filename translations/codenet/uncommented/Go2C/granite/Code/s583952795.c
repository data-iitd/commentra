
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int p1;
    int p2;
} Pair;

const int initialBufSize = 1e4;
const int maxBufSize = 1e8;

char buf[maxBufSize];
FILE *scanner = fmemopen(buf, initialBufSize, "r");
FILE *writer = stdout;

int main() {
    int N, K;
    fscanf(scanner, "%d %d", &N, &K);
    char *s = TenToN(N, K);
    fprintf(writer, "%d\n", strlen(s));
    return 0;
}

char *TenToN(int number, int n) {
    char *s = (char *)malloc(sizeof(char) * 100);
    int tmp = number;
    int i = 0;
    while (1) {
        s[i] = '0' + tmp % n;
        i++;
        if (tmp < n) {
            break;
        }
        tmp /= n;
    }
    s[i] = '\0';
    return s;
}

void write(char *s) {
    fprintf(writer, "%s", s);
}

void print() {
    fflush(writer);
}

char *readLine() {
    fgets(buf, maxBufSize, scanner);
    char *s = (char *)malloc(sizeof(char) * strlen(buf));
    strcpy(s, buf);
    return s;
}

int readInt() {
    int read;
    fscanf(scanner, "%d", &read);
    return read;
}

float readFloat() {
    float read;
    fscanf(scanner, "%f", &read);
    return read;
}

void readRunes() {
    // Implement this function if needed
}

char *readString() {
    char *s = (char *)malloc(sizeof(char) * 100);
    fgets(s, 100, scanner);
    return s;
}

char **readStrings() {
    // Implement this function if needed
}

int s2i(char *s) {
    int intVal;
    sscanf(s, "%d", &intVal);
    return intVal;
}

char *i2s(int i) {
    char *strVal = (char *)malloc(sizeof(char) * 10);
    sprintf(strVal, "%d", i);
    return strVal;
}

float s2f(char *s) {
    float floatVal;
    sscanf(s, "%f", &floatVal);
    return floatVal;
}

int sum(int *i, int size) {
    int sum = 0;
    for (int j = 0; j < size; j++) {
        sum += i[j];
    }
    return sum;
}

char **split(char *s) {
    // Implement this function if needed
}

int *strAry2intAry(char **strs, int size) {
    int *ret = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        ret[i] = s2i(strs[i]);
    }
    return ret;
}

char **intAry2strAry(int *nums, int size) {
    char **ret = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        ret[i] = i2s(nums[i]);
    }
    return ret;
}

char *ary2str(char **strs, int size) {
    // Implement this function if needed
}

void reverse(int *res, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
}

void initalize(int *res, int size, int init) {
    if (size == 0) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < size; i++) {
        memmove(res + i, res, sizeof(int) * i);
    }
}

// Implement the remaining functions if needed

