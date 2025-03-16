#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    char s[1000000];
    scanf("%s", s);
    int len = strlen(s);
    int even[1000000] = {0};
    int odd[1000000] = {0};
    for (int i = 0; i < len/2; i++)
    {
        even[i] = s[i] - '0';
    }
    for (int i = len/2; i < len; i++)
    {
        odd[i] = s[i] - '0';
    }
    int min = len;
    for (int i = 0; i < len/2; i++)
    {
        min = min < len - even[i] - odd[i]? min : len - even[i] - odd[i];
    }
    for (int i = len/2; i < len; i++)
    {
        min = min < len - odd[i] - even[i]? min : len - odd[i] - even[i];
    }
    printf("%d", min);
    return 0;
}

