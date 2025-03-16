
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, K;
    char S[1000000];
    int aaaa = 0;
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    if (K >= 15)
    {
        aaaa = 1;
    }
    else if (pow(2, K) >= N)
    {
        aaaa = 1;
    }
    if (aaaa == 1)
    {
        printf("%c", min(S));
        exit(0);
    }
    char *get_last_dict(char *s_str)
    {
        char U[1000000];
        strcpy(U, s_str);
        strcat(U, s_str);
        char c = min(s_str);
        int p = strchr(U, c) - U;
        int minindex = p;
        p++;
        while (p <= N)
        {
            if (U[p] == c)
            {
                if (check_normal_dict(U, minindex, p))
                {
                    minindex = p;
                }
            }
            p++;
        }
        return U + minindex;
    }
    int check_normal_dict(char *u, int pointer1, int pointer2)
    {
        for (int i = 0; i < N; i++)
        {
            if (u[pointer1 + i] > u[pointer2 + i])
            {
                return 1;
            }
            else if (u[pointer1 + i] < u[pointer2 + i])
            {
                return 0;
            }
        }
        return 0;
    }
    char *S = get_last_dict(S);
    if (K == 1)
    {
        printf("%s", S);
    }
    else
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == S[0])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count * (int)pow(2, K - 1) >= N)
        {
            printf("%c", S[0]);
        }
        else
        {
            char *S1 = (char *)malloc(sizeof(char) * (N + 1));
            strcpy(S1, S);
            for (int i = 0; i < count * (int)pow(2, K - 1) - 1; i++)
            {
                strcat(S1, S);
            }
            printf("%s", S1);
        }
    }
    return 0;
}

