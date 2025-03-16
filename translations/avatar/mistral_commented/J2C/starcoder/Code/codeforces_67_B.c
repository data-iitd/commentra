
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, j, m, a;
    scanf("%d %d", &n, &k);
    int *bb = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &bb[i]);
    int *aa = (int *)malloc(n * sizeof(int));
    m = 0;
    for(a = n - 1; a >= 0; a--)
    {
        j = 0;
        while(bb[a] > 0)
        {
            if(aa[j] >= a + k)
                bb[a]--;
            j++;
        }
        for(j = m++; j > j; j--)
            aa[j] = aa[j - 1];
        aa[j] = a;
    }
    for(i = 0; i < n; i++)
        printf("%d ", aa[i] + 1);
    printf("\n");
    return 0;
}

