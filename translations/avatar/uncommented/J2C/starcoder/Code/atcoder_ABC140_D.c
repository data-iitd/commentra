#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K;
    char S[100000];
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    char c1[100000], c3[100000];
    int flag = 0, count = 0, sum1 = 0, sum3 = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag && S[i] == 'R')
        {
            flag = 0;
            count++;
        }
        if (count == K)
            break;
        if (S[i] == 'L')
        {
            flag = 1;
            c1[i] = 'R';
        }
    }
    flag = 0;
    count = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag && S[i] == 'L')
        {
            flag = 0;
            count++;
        }
        if (count == K)
            break;
        if (S[i] == 'R')
        {
            flag = 1;
            c3[i] = 'L';
        }
    }
    char bef = c1[0];
    for (int i = 1; i < N; i++)
    {
        if (c1[i] == bef)
        {
            count++;
            if (i == N - 1)
                sum1 += count - 1;
        }
        else
        {
            bef = c1[i];
            sum1 += count - 1;
            count = 1;
        }
    }
    bef = c3[0];
    for (int i = 1; i < N; i++)
    {
        if (c3[i] == bef)
        {
            count++;
            if (i == N - 1)
                sum3 += count - 1;
        }
        else
        {
            bef = c3[i];
            sum3 += count - 1;
            count = 1;
        }
    }
    printf("%d\n", (sum1 > sum3)? sum1 : sum3);
    return 0;
}

