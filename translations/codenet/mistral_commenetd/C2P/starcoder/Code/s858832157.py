#include <stdio.h>

#define MAX_CASES 1000

int main()
{
    int i = 1;
    int Input;

    while(1)
    {
        scanf("%d", &Input);

        if(Input == 0):
            break;

        printf("Case %d: %d\n", i, Input);

        i++;
    }

    return 0;
}

