#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int readFloat() {
    float n;
    scanf("%f", &n);
    return (int)n;
}

int stringToInt(char *s) {
    return atoi(s);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = readInt();
    int as[n];
    for (int i = 0; i < n; i++) {
        as[i] = readInt();
    }

    int xs[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int pos = (int)(lower_bound(xs, xs + size, as[i]) - xs);
        xs[pos] = as[i];
        if (pos == size) {
            size++;
        }
    }

    printf("%d\n", size);
    return 0;
}

