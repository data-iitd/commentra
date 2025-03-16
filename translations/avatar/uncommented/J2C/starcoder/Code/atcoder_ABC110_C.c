#include <stdio.h>
#include <string.h>

int main()
{
    char S[100000], T[100000];
    scanf("%s", S);
    scanf("%s", T);
    int A[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        A[i] = 'a' + i;
    }
    int res = 1;
    for (int i = 0; i < 26; i++)
    {
        int sIdx = strchr(S, A[i]) - S;
        if (sIdx < 0) continue;
        char t = T[sIdx];
        int idx = 0;
        while (idx < strlen(S))
        {
            if (strchr(S, A[i], idx) >= 0)
            {
                if (strchr(S, A[i], idx)!= strchr(T, t, idx))
                {
                    res = 0;
                    break;
                }
                else
                {
                    idx = strchr(S, A[i], idx) + 1;
                }
            }
            else if (strchr(T, t, idx) >= 0)
            {
                res = 0;
                break;
            }
            else break;
        }
        if (!res) break;
    }
    if (res) printf("Yes\n");
    else printf("No\n");
    return 0;
}
