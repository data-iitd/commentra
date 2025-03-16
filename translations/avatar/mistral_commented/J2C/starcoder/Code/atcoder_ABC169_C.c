
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long a;
    scanf("%ld", &a);

    char b[100000];
    scanf("%s", b);

    int length = strlen(b);
    char bChar[length];
    int i;
    for (i = 0; i < length; i++)
    {
        if (b[i]!= '.')
        {
            bChar[i] = b[i];
        }
    }

    int bInt;
    bInt = atoi(bChar);

    long result;
    result = (a * bInt) / 100;

    printf("%ld\n", result);

    return 0;
}

