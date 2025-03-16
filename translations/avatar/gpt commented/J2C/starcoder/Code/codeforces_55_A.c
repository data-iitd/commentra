#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i = 1, k = 0, p = 1;
    bool flag = true;
    int a[1000]; // Array to keep track of occurrences

    scanf("%d", &n);

    while(i <= n)
    {
        if(flag)
        {
            a[k] = i;
            k++;
            flag = false;
        }
        else
        {
            if(a[k-1] == i)
            {
                k--;
                p++;
            }
            else
            {
                a[k] = i;
                k++;
            }
        }
        i++;
    }

    printf("%d", p);

    return 0;
}

