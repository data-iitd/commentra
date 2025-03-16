#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char S[1000000];
    int march[5] = {0};
    for (int i = 0; i < N; i++)
    {
        scanf("%s", S);
        if (S[0] == 'M' || S[0] =='m')
            march[0]++;
        if (S[0] == 'A' || S[0] == 'a')
            march[1]++;
        if (S[0] == 'R' || S[0] == 'r')
            march[2]++;
        if (S[0] == 'C' || S[0] == 'c')
            march[3]++;
        if (S[0] == 'H' || S[0] == 'h')
            march[4]++;
    }
    int ans = 0;
    for (int x = 0; x < march[0]; x++)
        for (int y = 0; y < march[1]; y++)
            for (int z = 0; z < march[2]; z++)
                ans += x * y * z;
    printf("%d\n", ans);
    return 0;
}

