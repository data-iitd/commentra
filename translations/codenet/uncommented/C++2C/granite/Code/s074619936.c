
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    char tmp[10];
    int sum;

    while(1)
    {
        scanf("%s", str);
        if(strcmp(str, "0") == 0) break;
        sum = 0;
        for(int i=0;i<strlen(str);i++)
        {
            tmp[0] = str[i];
            tmp[1] = '\0';
            int num = atoi(tmp);
            sum += num;
        }
        
        printf("%d\n", sum);
    }
    return 0;
}
