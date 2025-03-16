#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX
#define MOD 1000000007

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int result = max(max(a * c, b * d), max(a * d, b * c));
    printf("%d\n", result);
    return 0;
}

