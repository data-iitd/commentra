#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, k, r;
    int *L;
    scanf("%d", &k);
    L = (int *) malloc(sizeof(int) * k);
    r = 1;
    for(i = 0; i < k; i++)
    {
        scanf("%d", &L[i]);
        r += L[i];
    }
    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        scanf("%d", &j);
        printf("%d\n", L[j - 1]);
    }
    return 0;
}
