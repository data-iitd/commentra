
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000000];
    scanf("%s", a);
    int count = 0;
    int i = 0;
    while (a[i]!= '\0')
    {
        if (a[i] == '1')
        {
            count++;
        }
        i++;
    }
    if (count == 0)
    {
        printf("0");
    }
    else
    {
        int j = 0;
        int k = 0;
        int temp = 0;
        while (a[j]!= '\0')
        {
            if (a[j] == '0')
            {
                temp++;
            }
            else
            {
                if (temp!= 0)
                {
                    count = count * (temp + 1);
                    temp = 0;
                }
            }
            j++;
        }
        if (temp!= 0)
        {
            count = count * (temp + 1);
        }
        printf("%d", count);
    }
    printf("\n");
    return 0;
}

