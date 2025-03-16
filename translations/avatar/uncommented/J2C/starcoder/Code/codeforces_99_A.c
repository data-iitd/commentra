#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    char str[100000];
    scanf("%s", str);
    int dotIndex = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '.')
        {
            dotIndex = i;
            break;
        }
    if (str[dotIndex - 1] == '9')
    {
        printf("GOTO Vasilisa.\n");
    }
    else if (str[dotIndex + 1] - '0' > 4)
    {
        char _str[100000];
        for (int i = 0; i < dotIndex; i++)
            _str[i] = str[i];
        printf("%s\n", strtoull(_str, NULL, 10) + 1);
    }
    else
    {
        for (int i = 0; i < dotIndex; i++)
            printf("%c", str[i]);
        printf("\n");
    }
    return 0;
}

