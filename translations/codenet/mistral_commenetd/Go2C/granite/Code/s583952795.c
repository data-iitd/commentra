
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int p1;
    int p2;
} Pair;

#define initialBufSize 1000
#define maxBufSize 1000000

int N, K;
char buf[maxBufSize];

int main() {
    scanf("%d %d", &N, &K);
    char *s = TenToN(N, K);
    printf("%d\n", strlen(s));
    return 0;
}

char *TenToN(int number, int n) {
    char *s = (char *)malloc(initialBufSize * sizeof(char));
    int tmp = number;
    int i = 0;
    while (tmp >= n) {
        s[i++] = (tmp % n) + '0';
        tmp /= n;
    }
    s[i++] = tmp + '0';
    s[i] = '\0';
    char *result = (char *)malloc(i * sizeof(char));
    for (int j = 0; j < i; j++) {
        result[j] = s[i - 1 - j];
    }
    free(s);
    return result;
}

// 