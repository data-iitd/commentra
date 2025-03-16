#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int candeleIntere, b, s, restoSciolte;
    scanf("%d %d", &candeleIntere, &b);
    s = 0;
    restoSciolte = 0;
    while (candeleIntere > 0 || restoSciolte >= b)
    {
        candeleIntere += restoSciolte / b;
        restoSciolte %= b;
        s += candeleIntere;
        restoSciolte += candeleIntere % b;
        candeleIntere /= b;
    }
    printf("%d", s);
    return 0;
}
