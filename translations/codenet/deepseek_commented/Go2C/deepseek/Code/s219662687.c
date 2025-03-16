#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF (int)(1e11)

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

float nextFloat() {
    float n;
    scanf("%f", &n);
    return n;
}

char* nextString() {
    char *str = (char*)malloc(10000 * sizeof(char));
    scanf("%s", str);
    return str;
}

int abs(int x) {
    return (int)fabs(x);
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int A = nextInt();
    int B = nextInt();
    int Q = nextInt();
    int s[A+2];
    s[0] = -INF;
    s[A+1] = INF;
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
    }

    int t[B+2];
    t[0] = -INF;
    t[B+1] = INF;
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
    }

    for (int i = 0; i < Q; i++) {
        int x = nextInt();
        int b = 0, d = 0;
        for (int j = 0; j <= A; j++) {
            if (s[j] <= x && s[j+1] >= x) {
                b = j;
                break;
            }
        }
        for (int j = 0; j <= B; j++) {
            if (t[j] <= x && t[j+1] >= x) {
                d = j;
                break;
            }
        }

        int res = INF;
        for (int j = b-1; j <= b; j++) {
            for (int k = d-1; k <= d; k++) {
                int d1 = abs(s[j] - x) + abs(t[k] - s[j]);
                int d2 = abs(t[k] - x) + abs(s[j] - t[k]);
                res = min(res, min(d1, d2));
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
