_
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0;
    char input[1000];
    scanf("%s", input);
    for (int i = 0; input[i]!= '\0'; i++)
    {
        if (input[i] == '0')
        {
            break;
        }
        result++;
    }
    printf("%d\n", result);
    return 0;
}
