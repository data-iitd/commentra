#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, a, sho, am;

    scanf("%d %d", &h, &a);

    sho = h / a;
    am = h % a;

    if (am!= 0)
    {
        sho += 1;
    }

    printf("%d", sho);

    return 0;
}
