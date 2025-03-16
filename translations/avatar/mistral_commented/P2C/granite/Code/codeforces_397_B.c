
###
#include <stdio.h>
###

int main ( void )
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        printf("%s\n", ( a % b == 0 || a / b >= k )? "Yes" : "No");
    }
    return 0;
}
