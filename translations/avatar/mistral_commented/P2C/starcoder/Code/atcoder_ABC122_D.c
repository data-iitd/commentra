
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int main()
{
    int n;
    scanf("%d", &n);
    
    int memo[n+1][4];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 4; j++)
            memo[i][j] = -1;
    
    int ret = 0;
    for (int i = 0; i < 4; i++)
        if (ok("TTT", i))
            ret = (ret + dfs(0, "TTT", i)) % mod;
    
    printf("%d\n", ret);
    
    return 0;
}

int dfs(int cur, char last3[], int last3_idx)
{
    if (memo[cur][last3_idx]!= -1)
        return memo[cur][last3_idx];
    
    if (cur == n)
        return 1;
    
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        if (ok(last3, last3_idx, i))
            ret = (ret + dfs(cur+1, last3, i)) % mod;
    }
    
    memo[cur][last3_idx] = ret;
    return ret;
}

bool ok(char last3[], int last3_idx, int c)
{
    char t[4];
    for (int i = 0; i < 4; i++)
    {
        t[i] = last3[(last3_idx + i) % 3];
    }
    
    t[last3_idx] = c;
    
    for (int i = 0; i < 4; i++)
    {
        if (t[i] == 'A' && t[(i+1) % 4] == 'G' && t[(i+2) % 4] == 'C')
            return false;
    }
    
    return true;
}

