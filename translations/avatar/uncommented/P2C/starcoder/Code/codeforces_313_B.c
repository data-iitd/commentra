#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char soz[100000];
    int a[100000];
    int i, n;
    scanf("%s", soz);
    a[0] = 0;
    for(i=1; i<strlen(soz); i++)
    {
        a[i] = a[i-1];
        if(soz[i-1] == soz[i])
            a[i]++;
    }
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
    {
        int m, l;
        scanf("%d %d", &m, &l);
        arr[i] = a[l-1] - a[m-1];
    }
    for(i=0; i<n; i++)
        printf("%d\n", arr[i]);
    return 0;
}
