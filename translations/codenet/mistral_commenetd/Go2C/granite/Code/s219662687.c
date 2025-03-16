
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000

int nextInt();
float nextFloat();
char* nextString();

int main() {
    const int A = nextInt(), B = nextInt(), Q = nextInt();
    int s[A + 2], t[B + 2];
    for (int i = 0; i < A + 2; i++) {
        s[i] = -INF;
    }
    s[A + 1] = INF;
    for (int i = 0; i < A; i++) {
        s[i + 1] = nextInt();
    }
    for (int i = 0; i < B + 2; i++) {
        t[i] = -INF;
    }
    t[B + 1] = INF;
    for (int i = 0; i < B; i++) {
        t[i + 1] = nextInt();
    }
    for (int i = 0; i < Q; i++) {
        int x = nextInt();
        int b = 0, d = 0;
        while (s[b + 1] <= x) {
            b++;
        }
        while (t[d + 1] <= x) {
            d++;
        }
        int res = INF;
        for (int S : {s[b], s[b - 1]}) {
            for (int T : {t[d], t[d - 1]}) {
                int d1 = abs(S - x), d2 = abs(T - S);
                res = fmin(res, fmin(d1, d2));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

float nextFloat() {
    float num;
    scanf("%f", &num);
    return num;
}

char* nextString() {
    int str_size = 0;
    char* str = NULL;
    while ((str = (char*)realloc(str, sizeof(char) * ++str_size)) == NULL)
        ;
    scanf("%s", str);
    return str;
}

// Translate the above C code to Java and end with comment "