#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000000
#define MOD 1000000007

int main()
{
    int n, m, i, j, x, y, w_x, r_x, w_y, r_y, ans = 0;
    scanf("%d %d", &n, &m);
    int balls[n][2] = {0};
    for(i = 0; i < n; i++)
    {
        balls[i][0] = 1;
        balls[i][1] = 0;
    }
    balls[0][0] = 0;
    balls[0][1] = 1;
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        w_x = balls[x-1][0];
        r_x = balls[x-1][1];
        w_y = balls[y-1][0];
        r_y = balls[y-1][1];
        if(w_x >= 1 && r_x >= 1)
        {
            balls[x-1][0] -= 1;
            balls[y-1][1] += 1;
        }
        else if(w_x == 0)
        {
            balls[x-1][1] -= 1;
            balls[y-1][1] += 1;
        }
        else
        {
            balls[x-1][0] -= 1;
            balls[y-1][0] += 1;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(balls[i][1])
            ans++;
    }
    printf("%d", ans);
    return 0;
}
