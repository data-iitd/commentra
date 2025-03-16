#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, result, amari;
    scanf("%d %d", &A, &B);
    result = (B - 1) / (A - 1);
    amari = (B - 1) % (A - 1);
    if (amari!= 0)
        result += 1;
    printf("%d\n", result);
    return 0;
}
