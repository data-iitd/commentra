#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    char tmp[100];
    int sum;

    while(1)
    {
        scanf("%s", str);
        if(strcmp(str, "0") == 0) break;
        sum = 0;
        for(int i=0;i<strlen(str);i++)
        {
            sprintf(tmp, "%c", str[i]);
            int num = atoi(tmp);
            sum += num;
        }
        
        printf("%d\n", sum);
    }
    return 0;
}

