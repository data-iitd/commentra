#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k, i, j, a, m;
    int *bb, *aa;

    scanf("%d %d", &n, &k);
    bb = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &bb[i]);

    aa = (int *)malloc(n * sizeof(int));
    m = 0;

    for (a = n - 1; a >= 0; a--) {
        j = 0;
        while (bb[a] > 0) {
            if (aa[j] >= a + k)
                bb[a]--;
            j++;
        }
        for (int j_ = m++; j_ > j; j_--)
            aa[j_] = aa[j_ - 1];
        aa[j] = a;
    }

    for (i = 0; i < n; i++)
        printf("%d ", aa[i] + 1);
    printf("\n");

    free(bb);
    free(aa);

    return 0;
}

