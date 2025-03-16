#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1001

void scanString(char *str) {
    scanf("%s", str);
}

void scanRunes(char *str) {
    scanf("%s", str);
}

int scanInt() {
    int a;
    scanf("%d", &a);
    return a;
}

long long scanInt64() {
    long long a;
    scanf("%lld", &a);
    return a;
}

double scanFloat64() {
    double a;
    scanf("%lf", &a);
    return a;
}

void scanInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void debug(int a, ...) {
    printf("%d\n", a);
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void restoreString(char *s, char *t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    char *ans[MAX_LEN];
    int count = 0;

    for (int i = 0; i <= lenS - lenT; i++) {
        char ss[MAX_LEN];
        strcpy(ss, s);
        int f = 1;

        for (int j = 0; j < lenT; j++) {
            if (ss[i + j] != t[j] && ss[i + j] != '?') {
                f = 0;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }

        if (f) {
            for (int k = 0; k < lenS; k++) {
                if (ss[k] == '?') {
                    ss[k] = 'a';
                }
            }
            ans[count++] = strdup(ss);
        }
    }

    if (count == 0) {
        printf("UNRESTORABLE\n");
    } else {
        qsort(ans, count, sizeof(char*), (int (*)(const void*, const void*))strcmp);
        printf("%s\n", ans[0]);
    }
}

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    scanString(s);
    scanString(t);
    restoreString(s, t);
    return 0;
}
