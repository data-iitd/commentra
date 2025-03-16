#include <stdio.h>
#include <string.h>

#define max(a, b) (a > b ? a : b)

#define data [111111]
#define seq [222222]

def main():
    n, k, t, i, p, ret = 0, 0, 0, 0, 0, 0

    while True:
        scanf("%d %d", &n, &k)
        if n == 0 and k == 0:
            break

        memset(data, 0, sizeof(data))
        memset(seq, 0, sizeof(seq))

        for i in range(k):
            scanf("%d", &t)
            data[t] += 1

        p = 0
        for i in range(1, n + 1):
            if data[i]:
                seq[p] += 1
            else:
                p += 2

        p += 1

        if data[0]:
            for i in range(p):
                ret = max(ret, seq[i] + seq[i + 2] + 1)
        else:
            for i in range(p):
                ret = max(ret, seq[i])

        printf("%d\n", ret)

    return 0

