
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

int main()
{
    char s[100000];
    scanf("%s", s);
    int even[26] = {0};
    int odd[26] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        if (i % 2 == 0)
        {
            even[s[i] - 'a']++;
        }
        else
        {
            odd[s[i] - 'a']++;
        }
    }
    int min = INT_MAX;
    min = min < strlen(s) - (even[0] + odd[1])? min : strlen(s) - (even[0] + odd[1]);
    min = min < strlen(s) - (even[1] + odd[0])? min : strlen(s) - (even[1] + odd[0]);
    printf("%d", min);
    return 0;
}

