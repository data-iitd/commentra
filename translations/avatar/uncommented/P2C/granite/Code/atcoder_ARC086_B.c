
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
typedef long double LD;
using namespace std;

const int MOD = 1e9 + 7;
const int oo = INT_MAX;
const LL OO = 1e18;

const int N = 1e6 + 100;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int max_val = 0, max_sign = 0, max_index = -1;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = a[i] > 0? 1 : (a[i] < 0? -1 : 0);
            max_index = i;
        }
    }
    if (max_sign == 0) {
        puts("0");
    } else if (max_sign == 1) {
        printf("%d\n", 2 * n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            printf("%d %d\n", i + 1, i + 2);
        }
    } else {
        printf("%d\n", 2 * n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = n - 1; i > 0; --i) {
            printf("%d %d\n", i + 1, i);
        }
    }
    return 0;
}
