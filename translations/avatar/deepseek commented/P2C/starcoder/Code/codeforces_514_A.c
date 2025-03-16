
#include <stdio.h>
#include <string.h>

int main()
{
    char ip[1000];
    scanf("%s", ip);
    char st[1000];
    st[0] = '\0';
    if (strlen(ip)!= 1)
    {
        if (ip[0] == '9')
        {
            strcat(st, "9");
            ip[0] = '\0';
        }
        for (int i = 0; ip[i]!= '\0'; i++)
        {
            if (ip[i] - '0' > 4)
            {
                int n = 9 - (ip[i] - '0');
                strcat(st, (char *) &n);
            }
            else
            {
                strcat(st, ip[i]);
            }
        }
    }
    else
    {
        strcpy(st, ip);
    }
    printf("%d", atoi(st));
    return 0;
}

