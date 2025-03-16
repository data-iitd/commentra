
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory.h>

typedef long long LL;

int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

LL readLL() {
    LL n;
    scanf("%lld", &n);
    return n;
}

double readDouble() {
    double n;
    scanf("%lf", &n);
    return n;
}

char readChar() {
    char n;
    scanf("%c", &n);
    return n;
}

void read(char *buf) {
    scanf("%s", buf);
}

void solve() {
    int n = readInt();
    if (n == 1) {
        printf("0\n");
        return;
    }
    std::vector<int> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        p.push_back(n);
    }
    std::sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 1; i <= 99999999; i++) {
        int x = i;
        for (int j = 0; j < p.size(); j++) {
            while (x % p[j] == 0) {
                x /= p[j];
            }
        }
        if (x == 1) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}

