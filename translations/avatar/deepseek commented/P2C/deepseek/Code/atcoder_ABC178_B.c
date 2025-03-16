#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 10000000000000000000
#define MOD 1000000007

typedef long long ll;

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int result = fmax(a * c, fmax(b * d, fmax(a * d, b * c)));
    printf("%d\n", result);
    return 0;
}
