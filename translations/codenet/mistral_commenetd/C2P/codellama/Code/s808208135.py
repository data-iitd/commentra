#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define INF 1000000

typedef struct
{
    int go, back, cost;
} Date;

n = 0
d = [0] * N
a = [0] * 500000

def root(b):
    i = 0
    flag = 1

    for i in range(N):
        d[i] = INF

    d[0] = 0

    while flag != 0:
        flag = 0

        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = 1

def main():
    global n
    global d
    global a

    scanf("%d", &n)

    for i in range(n):
        scanf("%d%d", &u, &k)

        for j in range(k):
            a[count].back = u
            scanf("%d%d", &a[count].go, &a[count].cost)
            count += 1

    root(count)

    for i in range(n):
        printf("%d %d\n", i, d[i])

    return 0

