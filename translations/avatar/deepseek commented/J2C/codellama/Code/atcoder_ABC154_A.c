
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a BufferedReader to read input from the standard input stream
    char *str[100];
    int a, b;
    char u[100];
    scanf("%s", str);
    scanf("%d %d", &a, &b);
    scanf("%s", u);
    if (strcmp(u, str[0]) == 0)
    {
        printf("%d %d", a - 1, b);
    }
    else
    {
        printf("%d %d", a, b - 1);
    }
    return 0;
}

