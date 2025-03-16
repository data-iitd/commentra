#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>

#define setrecursionlimit(x)

#define dbg(x) printf x

#define input() fgets(buffer, sizeof(buffer), stdin)

#define LMIIS(a, n) for (int i = 0; i < n; i++) scanf("%d", &a[i])

#define II() int num; scanf("%d", &num); return num

#define P 1000000007

#define INF 1000000001

int main() {
    char buffer[100];
    char sa[10], sb[10];
    int a;
    int b;

    input();
    sscanf(buffer, "%s %s", sa, sb);

    a = atoi(sa);
    b = (int)(atof(sb) * 100 + 0.1);

    printf("%d\n", a * b / 100);

    return 0;
}

