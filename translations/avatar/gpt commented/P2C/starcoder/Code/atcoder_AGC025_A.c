#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[100000];
    scanf("%s", n);
    int sum = 0;
    for (int i = 0; i < strlen(n); i++)
    {
        sum += n[i] - '0';
    }
    if (sum == 10 || sum == 100 || sum == 1000 || sum == 10000 || sum == 100000)
    {
        printf("10\n");
    }
    else
    {
        printf("%d\n", sum);
    }
    return 0;
}
