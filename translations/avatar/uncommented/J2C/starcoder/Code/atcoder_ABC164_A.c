#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[10000];
    int Sheep, Wolve;
    int i, j;
    int flag = 0;
    while(1)
    {
        gets(str);
        if(str[0] == '0' && str[1] == '\0')
            break;
        Sheep = atoi(str);
        Wolve = atoi(str + strlen(str) - strlen(str) + 1);
        if(Wolve >= Sheep)
        {
            printf("unsafe\n");
            flag = 1;
        }
        else
            printf("safe\n");
    }
    if(flag == 0)
        printf("safe\n");
    return 0;
}
