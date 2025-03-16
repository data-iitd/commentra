#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input_array[1000];
    scanf("%s", input_array);

    int result = 0;

    for (int i = 0; input_array[i]!= '\0'; i++)
    {
        result++;

        if (input_array[i] == '0')
            break;
    }

    printf("%d\n", result);

    return 0;
}

