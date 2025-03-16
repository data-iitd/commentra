#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a;
    char b[1000];
    scanf("%ld", &a);
    scanf("%s", b);
    int length = strlen(b);
    int bInt = 0;
    for (int i = 0; i < length; i++)
    {
        if (b[i]!= '.')
        {
            bInt = bInt * 10 + (b[i] - '0');
        }
    }
    long result = (a * bInt) / 100;
    printf("%ld\n", result);
    return 0;
}
