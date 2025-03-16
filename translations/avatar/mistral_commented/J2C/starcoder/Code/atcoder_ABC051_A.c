
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100000];
    scanf("%s", a);
    int i, j, k;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == ',')
        {
            for (j = i; j < strlen(a); j++)
            {
                a[j] = a[j + 1];
            }
            a[j] ='';
        }
    }
    printf("%s", a);
    return 0;
}

