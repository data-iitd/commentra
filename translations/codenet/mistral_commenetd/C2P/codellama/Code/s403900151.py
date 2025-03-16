#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 51

def main():
    n = 0
    r = 0
    p = 0
    c = 0
    i = 0
    j = 0
    k = 0
    l = 0
    a = [0] * MAX_SIZE
    b = [0] * MAX_SIZE

    while True:
        scanf("%d %d ", &n, &r)
        if not n and not r:
            break

        for i in range(n):
            a[i] = i + 1

        for i in range(r):
            scanf("%d %d ", &p, &c)

            for j in range(c):
                b[j] = a[n - p - c + 1 + j]

            for j in range(p - 1):
                a[n - p + j + 1] = a[n - p + j]

            for j in range(n - p - c + 1, n - p - c + 1 + c):
                a[j] = b[j - n + p + c]

            printf("%d\n", a[n - 1])

    return 0

