#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1e11

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

double nextFloat() {
    double num;
    scanf("%lf", &num);
    return num;
}

char* nextString() {
    char *str = (char*)malloc(10000 * sizeof(char));
    scanf("%s", str);
    return str;
}

int abs(int x) {
    return abs(x);
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
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
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
        int b = binarySearch(s, A+1, x);
        int d = binarySearch(t, B+1, x);
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
