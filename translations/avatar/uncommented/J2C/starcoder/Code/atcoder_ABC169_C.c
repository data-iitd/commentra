#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long a, b, result;
    char bChar[1000];
    scanf("%ld", &a);
    scanf("%s", bChar);
    int length = strlen(bChar);
    char bStr[1000];
    for (int i = 0; i < length; i++)
    {
        if (bChar[i]!= '.')
        {
            strcat(bStr, bChar[i]);
        }
    }
    b = atoi(bStr);
    result = (a * b) / 100;
    printf("%ld\n", result);
    return 0;
}

