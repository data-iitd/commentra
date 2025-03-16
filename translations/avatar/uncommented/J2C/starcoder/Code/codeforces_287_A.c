#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[4][100];
    int i,j,u,yes;
    for(i=0;i<4;i++)
        scanf("%s",str[i]);
    for(u=0;u<2;u++)
    {
        for(i=0;i<2;i++)
        {
            if(str[u][i]==str[u][i+1] && (str[u+1][i]==str[u][i] || str[u+1][i+1]==str[u][i]))
                yes=1;
            else if(str[u+1][i]==str[u+1][i+1] && (str[u][i]==str[u+1][i] || str[u][i+1]==str[u+1][i]))
                yes=1;
            if(yes==1)
                break;
        }
        if(yes==1)
            break;
    }
    if(yes==0)
        printf("NO");
    else
        printf("YES");
    return 0;
}
