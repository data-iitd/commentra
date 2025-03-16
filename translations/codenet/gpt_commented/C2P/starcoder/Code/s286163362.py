#include <stdio.h>
#include <string.h>

#define MAX_N 111111
#define MAX_K 222222

#define TRUE 1
#define FALSE 0

#define SEQ_GAP 2

int main(void)
{
    int n, k, t, i, p, ret = 0;
    int data[MAX_N];
    int seq[MAX_K];

    while(1) {
        scanf("%d %d", &n, &k);
        if (!n &&!k) break;

        memset(data, 0, sizeof(data));
        memset(seq, 0, sizeof(seq));

        for (i = 0; i < k; i++) {
            scanf("%d", &t);
            data[t]++;
        }

        p = 0;
        for (i = 1; i <= n; i++) {
            if (data[i]) {
                seq[p]++;
            } else {
                p += SEQ_GAP;
            }
        }
        p++;

        if (data[0]) {
            for (i = 0; i < p; i++) {
                ret = max(ret, seq[i] + seq[i + 2] + 1);
            }
        } else {
            for (i = 0; i < p; i++) {
                ret = max(ret, seq[i]);
            }
        }

        printf("%d\n", ret);
    }

    return 0;
}

def max(a, b):
    if a > b:
        return a
    return b

