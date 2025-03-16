#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, j, o, e, l, r;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    o = 0;
    e = 0;
    for(i = 0; i < n; i++)
        if(arr[i] == 1)
            o++;
        else
            e++;
    char res[k];
    for(i = 0; i < k; i++)
    {
        scanf("%d %d", &l, &r);
        if((r - l + 1) % 2 == 1)
            res[i] = '0';
        else
        {
            if((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e)
                res[i] = '1';
            else
                res[i] = '0';
        }
    }
    for(i = 0; i < k; i++)
        printf("%c", res[i]);
    printf("\n");
    return 0;
}
