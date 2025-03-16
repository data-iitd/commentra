
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int N, K;
    char S[1000000];
    bool aaaa = false;
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    if (K >= 15)
    {
        aaaa = true;
    }
    else if (1 << K >= N)
    {
        aaaa = true;
    }
    if (aaaa)
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
    bool check_normal_dict(char *u, int pointer1, int pointer2)
    {
        for (int i = 0; i < N; i++)
        {
            if (u[pointer1 + i] > u[pointer2 + i])
            {
                return true;
            }
            else if (u[pointer1 + i] < u[pointer2 + i])
            {
                return false;
            }
        }
        return false;
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
        if (count * (1 << (K - 1)) >= N)
        {
            printf("%c", S[0]);
        }
        else
        {
            char *S = (char *)malloc(sizeof(char) * (count * (1 << (K - 1)) - 1) + N);
            memset(S, S[0], count * (1 << (K - 1)) - 1);
            strcpy(S + count * (1 << (K - 1)) - 1, S);
            printf("%s", S);
        }
    }
    return 0;
}

