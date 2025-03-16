#include <stdio.h>
#include <string.h>

int main()
{
    char ip[100];
    scanf("%s", ip);

    char st[100];
    st[0] = '9';
    st[1] = '\0';

    if (strlen(ip)!= 1)
    {
        if (ip[0] == '9')
        {
            st[0] = '9';
            strcpy(ip, ip + 1);
        }

        for (int i = 0; i < strlen(ip); i++)
        {
            if (ip[i] > '4')
            {
                int n = 9 - ip[i];
                strcat(st, &n);
            }
            else
            {
                strcat(st, &ip[i]);
            }
        }
    }

    printf("%d\n", atoi(st));

    return 0;
}

