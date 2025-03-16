#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];

char* next() {
    fgets(line, MAX_LINE_LENGTH, stdin);
    return line;
}

int nextInt() {
    next();
    return atoi(line);
}

float nextFloat64() {
    next();
    return atof(line);
}

int* nextInts(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        slice[i] = nextInt();
    }
    return slice;
}

int main() {
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    if (a + b >= c) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
