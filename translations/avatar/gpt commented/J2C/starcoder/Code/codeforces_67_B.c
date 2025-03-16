#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, j, m;
    scanf("%d %d", &n, &k);
    int *bb = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &bb[i]);
    int *aa = (int *) malloc(n * sizeof(int));
    m = 0;
    for (i = n - 1; i >= 0; i--) {
        j = 0;
        while (bb[i] > 0) {
            if (aa[j] >= i + k)
                bb[i]--;
            j++;
        }
        for (j = m++; j > j; j--)
            aa[j] = aa[j - 1];
        aa[j] = i;
    }
    for (i = 0; i < n; i++)
        printf("%d ", aa[i] + 1);
    printf("\n");
    return 0;
}

