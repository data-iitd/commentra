#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000000007

int main()
{
    int N;
    scanf("%d", &N);
    char S[N][10];
    int march[5] = {0};
    for(int i = 0; i < N; i++)
    {
        scanf("%s", S[i]);
        if(S[i][0] == 'M')
            march[0]++;
        else if(S[i][0] == 'A')
            march[1]++;
        else if(S[i][0] == 'R')
            march[2]++;
        else if(S[i][0] == 'C')
            march[3]++;
        else if(S[i][0] == 'H')
            march[4]++;
    }
    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(i!= j && j!= k && i!= k)
                {
                    ans += march[i] * march[j] * march[k];
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

