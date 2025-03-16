
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            strcpy(st, "9");
            ip[0] = '\0';
        }
        for (i = 0; i < strlen(ip); i++)
        {
            if (ip[i] > '4')
            {
                n = 9 - ip[i];
                strcat(st, n);
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
    printf("The IP address is: %s", st);
    return 0;
}
