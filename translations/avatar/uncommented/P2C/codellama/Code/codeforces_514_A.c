
#include <stdio.h>
#include <string.h>

int main()
{
    char ip[100];
    char st[100];
    int i, n;
    printf("Enter the IP address: ");
    scanf("%s", ip);
    if (strlen(ip) != 1)
    {
        if (ip[0] == '9')
        {
            st[0] = '9';
            strcpy(ip, ip + 1);
        }
        for (i = 0; i < strlen(ip); i++)
        {
            if (ip[i] > '4')
            {
                n = 9 - ip[i];
                st[i] = n;
            }
            else
            {
                st[i] = ip[i];
            }
        }
    }
    else
    {
        strcpy(st, ip);
    }
    printf("The IP address is: %s\n", st);
    return 0;
}

