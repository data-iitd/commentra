#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K;
    char S[100000];
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    
    int aaaa = 0;
    if (K >= 15)
        aaaa = 1;
    else if (2 ** K >= N)
        aaaa = 1;
    
    if (aaaa)
    {
        printf("%s", S);
        for (int i = 0; i < N; i++)
            printf("%c", S[0]);
        printf("\n");
        return 0;
    }
    
    char U[200000];
    strcpy(U, S);
    strcat(U, S);
    char c = S[0];
    int p = strstr(U, c) - U;
    int minindex = p;
    p += 1;
    
    while (p <= N)
    {
        if (U[p] == c)
        {
            if (check_normal_dict(U, minindex, p))
                minindex = p;
        }
        p += 1;
    }
    
    char S2[100000];
    strcpy(S2, U + minindex);
    printf("%s\n", S2);
    
    return 0;
}

int check_normal_dict(char *U, int pointer1, int pointer2)
{
    for (int i = 0; i < N; i++)
    {
        if (U[pointer1 + i] > U[pointer2 + i])
            return 1;
        else if (U[pointer1 + i] < U[pointer2 + i])
            return 0;
    }
    return 0;
}

