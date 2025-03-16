
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, temp1, temp2, ans2 = 0;
    scanf("%d %d", &N, &M);
    long long H[N];
    bool ans[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &H[i]);
        ans[i] = true;
    }
    for(int query = 0; query < M; query++)
    {
        scanf("%d %d", &temp1, &temp2);
        if(H[temp1 - 1] < H[temp2 - 1])
        {
            ans[temp1 - 1] = false;
        }
        else if(H[temp1 - 1] > H[temp2 - 1])
        {
            ans[temp2 - 1] = false;
        }
        else
        {
            ans[temp1 - 1] = false;
            ans[temp2 - 1] = false;
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(ans[i])
        {
            ans2++;
        }
    }
    printf("%d", ans2);
    return 0;
}

