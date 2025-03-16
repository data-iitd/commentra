
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    char vo[10] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    int i, j;

    scanf("%s", a);

    for (i = strlen(a) - 1; i >= 0; i--)
    {
        if (a[i] == ' ' || a[i] == '?')
            continue;
        else
        {
            for (j = 0; j < 10; j++)
            {
                if (a[i] == vo[j])
                {
                    printf("YES\n");
                    break;
                }
            }
            if (j == 10)
                printf("NO\n");
            break;
        }
    }

    return 0;
}

