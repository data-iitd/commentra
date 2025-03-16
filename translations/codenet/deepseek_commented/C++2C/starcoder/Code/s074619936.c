#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    int sum;
    while(1)
    {
        scanf("%s", str);
        if(strcmp(str, "0") == 0) break;
        sum = 0;
        for(int i=0;str[i]!='\0';i++)
        {
            sum += str[i] - '0';
        }
        printf("%d\n", sum);
    }
    return 0;
}
