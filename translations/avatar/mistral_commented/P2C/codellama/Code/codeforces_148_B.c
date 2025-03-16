
#include <stdio.h>

int main()
{
    int princess, dragon, t, f, c;
    int result = 0;
    int position;

    scanf("%d", &princess);
    scanf("%d", &dragon);
    scanf("%d", &t);
    scanf("%d", &f);
    scanf("%d", &c);

    if (dragon <= princess)
    {
        printf("0");
        return 0;
    }

    position = t * princess;

    while (position < c)
    {
        result += 1;
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }

    printf("%d", result);

    return 0;
}

