
#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    scanf("%s", a);
    char vo[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (int i = strlen(a) - 1; i >= 0; i--)
    {
        if (a[i] =='' || a[i] == '?')
            continue;
        else
        {
            if (a[i] == vo[0] || a[i] == vo[1] || a[i] == vo[2] || a[i] == vo[3] || a[i] == vo[4] || a[i] == vo[5] || a[i] == vo[6] || a[i] == vo[7] || a[i] == vo[8] || a[i] == vo[9] || a[i] == vo[10] || a[i] == vo[11])
                printf("YES\n");
            else
                printf("NO\n");
            break;
        }
    }
    return 0;
}

