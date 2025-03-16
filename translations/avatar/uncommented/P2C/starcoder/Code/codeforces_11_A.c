#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, m, q, i;
    scanf("%d %d", &n, &d);
    int x[n];
    for(i=0;i<n;i++)
        scanf("%d", &x[i]);
    m=0;
    for(i=0;i<n-1;i++)
    {
        q = (x[i]-x[i+1])/d + 1;
        m = m + q;
        x[i+1] = x[i+1] + q*d;
    }
    printf("%d", m);
    return 0;
}
