#include <stdio.h>

int main()
{
    int h, a, sho, am;

    scanf("%d %d", &h, &a);

    sho = h / a;
    am = h % a;

    if (am != 0)
    {
        sho++;
    }

    printf("%d", sho);

    return 0;
}

