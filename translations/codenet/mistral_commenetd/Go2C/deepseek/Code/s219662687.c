#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF (int)(1e11)

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
    char *str = (char*)malloc(100 * sizeof(char));
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

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int A = nextInt();
    int B = nextInt();
    int Q = nextInt();

    int s[A + 2];
    s[0] = -INF;
    s[A + 1] = INF;
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
    }

    int t[B + 2];
    t[0] = -INF;
    t[B + 1] = INF;
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
    }

    for (int i = 0; i < Q; i++) {
        int x = nextInt();
        int b = binarySearch(s, A + 2, x);
        int d = binarySearch(t, B + 2, x);

        int res = INF;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int S = (j == 0) ? s[b - 1] : s[b];
                int T = (k == 0) ? t[d - 1] : t[d];
                int d1 = abs(S - x);
                int d2 = abs(T - S);
                res = min(res, min(d1, d2));
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
