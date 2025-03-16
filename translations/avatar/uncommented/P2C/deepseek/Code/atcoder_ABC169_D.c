#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#define INF INT_MAX
#define MOD 1000000007

int input() {
    int c;
    while ((c = getchar()) != ' ' && c != '\n');
    return c;
}

int get_nums_l() {
    char str[100];
    fgets(str, 100, stdin);
    int nums[100];
    int count = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        nums[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return nums[0];
}

int get_nums_n(int n) {
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    return nums[0];
}

int get_all_int() {
    char str[100];
    fgets(str, 100, stdin);
    int nums[100];
    int count = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        nums[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return nums[0];
}

void rangeI(int* it, int l, int r) {
    for (int i = 0; it[i] != -1; i++) {
        if (l <= it[i] < r) {
            printf("%d ", it[i]);
        } else if (l >= r) {
            break;
        }
    }
    printf("\n");
}

void log(int args) {
    printf("DEBUG: %d\n", args);
}

int main() {
    int n = input();
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int prime_factorize(int n) {
        int a[100];
        int count = 0;
        while (n % 2 == 0) {
            a[count++] = 2;
            n /= 2;
        }
        for (int f = 3; f * f <= n; f += 2) {
            while (n % f == 0) {
                a[count++] = f;
                n /= f;
            }
        }
        if (n != 1) {
            a[count++] = n;
        }
        return count;
    }

    int fac_[100];
    int fac_count = prime_factorize(n);
    int fac[100] = {0};
    for (int i = 0; i < fac_count; i++) {
        fac[fac_[i]]++;
    }

    int ans = 0;
    for (int p = 0; p < 100; p++) {
        if (fac[p] == 0) continue;
        int x = fac[p];
        for (int i = 1; i < 99999999; i++) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }
    printf("%d\n", ans);
}
