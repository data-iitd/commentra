#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char S[N][100];
    int march[5] = {0};
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", S[i]);
        if (S[i][0] == 'M' || S[i][0] == 'A' || S[i][0] == 'R' || S[i][0] == 'C' || S[i][0] == 'H')
        {
            march[S[i][0] - 'A']++;
        }
    }
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            for (int z = 0; z < 5; z++)
            {
                ans += march[x] * march[y] * march[z];
            }
        }
    }
    printf("%d", ans);
    return 0;
}

