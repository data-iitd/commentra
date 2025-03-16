
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000

int nextInt();
float nextFloat();
char* nextString();

int abs(int x);
int min(int x, int y);
int max(int x, int y);

int main() {
    int A = nextInt();
    int B = nextInt();
    int Q = nextInt();
    int s[A + 2];
    int t[B + 2];
    s[0] = -INF;
    s[A + 1] = INF;
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
    }
    t[0] = -INF;
    t[B + 1] = INF;
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
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
        for (int S = s[b]; S <= s[b + 1]; S++) {
            for (int T = t[d]; T <= t[d + 1]; T++) {
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                res = min(res, min(d1, d2));
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
    while ((str = (char*)realloc(str, sizeof(char) * ++str_size)) == NULL);
    int ch;
    while ((ch = getchar())!= '\n') {
        str[str_size - 1] = ch;
    }
    str[str_size - 1] = '\0';
    return str;
}

int abs(int x) {
    return (int)fabs((double)x);
}

int min(int x, int y) {
    return x < y? x : y;
}

int max(int x, int y) {
    return x > y? x : y;
}

// END-OF-CODE