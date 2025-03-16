#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e11

int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

int binarySearch(int *arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int A = readInt();
    int B = readInt();
    int Q = readInt();

    int s[A + 2];
    s[0] = -INF;
    s[A + 1] = INF;
    for (int i = 1; i <= A; i++) {
        s[i] = readInt();
    }

    int t[B + 2];
    t[0] = -INF;
    t[B + 1] = INF;
    for (int i = 1; i <= B; i++) {
        t[i] = readInt();
    }

    for (int i = 0; i < Q; i++) {
        int x = readInt();
        int b = binarySearch(s, A + 2, x);
        int d = binarySearch(t, B + 2, x);
        int res = INF;

        for (int S : {s[b - 1], s[b]}) {
            for (int T : {t[d - 1], t[d]}) {
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                res = min(res, min(d1, d2));
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
