
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char str[100000];
    scanf("%s", str);
    char a[100000];
    for(int i = 0; i < n/2; i++)
    {
        a[i] = str[i];
    }
    if(strcmp(str, a) == 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}

