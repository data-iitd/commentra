#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    scanf("%s", a);
    for (int i = strlen(a) - 1; i >= 0; i--)
    {
        if (a[i] =='' || a[i] == '?')
        {
            continue;
        }
        else
        {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
            {
                printf("YES");
                break;
            }
            else
            {
                printf("NO");
                break;
            }
        }
    }
    return 0;
}
