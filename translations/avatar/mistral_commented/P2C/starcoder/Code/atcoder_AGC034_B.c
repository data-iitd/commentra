#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s", s);
    int i = 0, total = 0, numA = 0;
    while (s[i]!= '\0')
    {
        if (s[i] == 'X')
        {
            numA = 0;
        }
        else if (s[i] == 'A')
        {
            numA++;
        }
        total += numA;
        i++;
    }
    printf("%d", total);
    return 0;
}

