#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 10000000
#define INF 100000000

typedef struct {
    int index;
    int p1, p2;
} pair;

typedef struct {
    pair data[100000];
    int size;
} pairs;

typedef struct {
    int data[100000];
    int size;
} Int64Slice;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

void readInt(int *n) {
    char ch;
    while ((ch = getchar()) < '0' || ch > '9');
    *n = 0;
    while (ch >= '0' && ch <= '9') {
        *n = (*n << 3) + (*n << 1) + (ch - '0');
        ch = getchar();
    }
}

void write(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        putchar(s[i]);
    }
}

void print() {
    fflush(stdout);
}

int main() {
    int A, B, C;
    readInt(&A);
    readInt(&B);
    readInt(&C);

    if (C >= A && C <= B) {
        write("Yes\n");
    } else {
        write("No\n");
    }
    print();

    return 0;
}

