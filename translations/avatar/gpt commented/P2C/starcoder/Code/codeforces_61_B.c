#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    char s1[100000];
    char s2[100000];
    char s3[100000];
    scanf("%s", s);
    scanf("%s", s1);
    scanf("%s", s2);
    strcpy(s3, s);
    strcat(s3, s1);
    strcat(s3, s2);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char s4[100000];
        scanf("%s", s4);
        if (strcmp(s4, s3) == 0)
        {
            printf("ACC\n");
        }
        else
        {
            printf("WA\n");
        }
    }
    return 0;
}

