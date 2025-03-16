
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100000];
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++)
    {
        scanf("%s", str);
        for(j=0;j<m;j++)
        {
            if(str[j]=='-')
                printf("-");
            else
            {
                if((i+j)%2==1)
                    printf("W");
                else
                    printf("B");
            }
        }
        printf("\n");
    }
    return 0;
}

