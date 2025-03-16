
#include <stdio.h>
#include <string.h>

int main( )
{
    char s[1000001];
    scanf("%s", s);
    int k;
    scanf("%d", &k);

    int l = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i]!= '1')
        {
            if (l >= k)
            {
                printf("1\n");
                return 0;
            }
            break;
        }
        l++;
    }

    printf("%c\n", s[l]);
    return 0;
}

