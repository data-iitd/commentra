#include<stdio.h>

int main(void):
    int i, j, x[10000]
    for i in range(0, 10000):
        x[i] = 0
    i = 0
    scanf("%d", &x[i])
    while x[i] != 0:
        i += 1
        scanf("%d", &x[i])
    for j in range(0, i):
        printf("Case %d: %d\n", j + 1, x[j])
    return 0

