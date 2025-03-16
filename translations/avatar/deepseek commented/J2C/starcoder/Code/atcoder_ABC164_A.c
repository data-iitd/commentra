
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    int sheep, wolves;
    scanf("%d %d", &sheep, &wolves);
    scanf("%s", input);
    if(wolves >= sheep)
        printf("unsafe");
    else
        printf("safe");
    return 0;
}

