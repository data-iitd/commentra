#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHOPS 100000

typedef struct {
    int a, b;
} Shop;

typedef struct {
    Shop shops[MAX_SHOPS];
    int size;
} Datas;

void out(int x, ...) {
    va_list args;
    va_start(args, x);
    printf("%d\n", x);
    va_end(args);
}

int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

char* getString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int asub(int a, int b) {
    return a > b ? a - b : b - a;
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int lowerBound(Shop* s, int size, int x) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (s[mid].a < x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int upperBound(Shop* s, int size, int x) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (s[mid].a <= x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

void sortShops(Shop* s, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (s[j].a > s[j + 1].a) {
                Shop temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N = getInt();
    int M = getInt();
    Shop s[MAX_SHOPS];
    for (int i = 0; i < N; i++) {
        s[i].a = getInt();
        s[i].b = getInt();
    }

    sortShops(s, N);

    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = min(s[i].b, M);
        total += n * s[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }

    out(total);

    return 0;
}
