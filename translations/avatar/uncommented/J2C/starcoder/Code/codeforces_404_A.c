#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char arr[n][n];
    char str[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = str[j];
        }
    }
    char a = arr[0][0];
    char b = arr[0][1];
    if(a == b)
    {
        printf("NO");
    }
    else
    {
        bool res = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || i + j == n - 1)
                {
                    if(arr[i][j]!= a)
                    {
                        res = false;
                        break;
                    }
                }
                else
                {
                    if(arr[i][j]!= b)
                    {
                        res = false;
                        break;
                    }
                }
            }
        }
        if(res)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    return 0;
}

