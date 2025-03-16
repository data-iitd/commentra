#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int w[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if(w[i] == 0)
        {
            c += w[i] * (w[i] - 1);
        }
        else
        {
            if(-w[i] == w[i])
            {
                c += w[i] * w[i];
            }
            else
            {
                if(-w[i] < w[i])
                {
                    c += w[i] * (w[i] - 1);
                }
                else
                {
                    c += w[i] * (w[i] - 1);
                }
            }
        }
    }
    printf("%d", c / 2);
    return 0;
}

