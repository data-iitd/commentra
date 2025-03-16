#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    char input[100];
    int a[100];
    int i, j;
    scanf("%s", input);
    for (i = 0; i < strlen(input); i++)
    {
        a[i] = input[i] - '0';
    }
    for (i = 1; i < strlen(input); i++)
    {
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
