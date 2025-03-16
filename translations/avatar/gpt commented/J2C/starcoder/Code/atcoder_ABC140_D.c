#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N];
    scanf("%s", S);
    int flag = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag && S[i] == 'R')
        {
            flag = 0;
            count++;
        }
        if (count == K)
        {
            break;
        }
        if (S[i] == 'L')
        {
            flag = 1;
            S[i] = 'R';
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
        {
            break;
        }
        if (S[i] == 'R')
        {
            flag = 1;
            S[i] = 'L';
        }
    }
    int sum1 = 0;
    int sum3 = 0;
    int count1 = 1;
    int count3 = 1;
    char bef1 = S[0];
    char bef3 = S[0];
    for (int i = 1; i < N; i++)
    {
        if (S[i] == bef1)
        {
            count1++;
            if (i == N - 1)
            {
                sum1 += count1 - 1;
            }
        }
        else
        {
            bef1 = S[i];
            sum1 += count1 - 1;
            count1 = 1;
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (S[i] == bef3)
        {
            count3++;
            if (i == N - 1)
            {
                sum3 += count3 - 1;
            }
        }
        else
        {
            bef3 = S[i];
            sum3 += count3 - 1;
            count3 = 1;
        }
    }
    printf("%d\n", max(sum1, sum3));
    return 0;
}

