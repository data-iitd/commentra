
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, count, max, idx, ans;
    char input[100000];
    int msgLength[100000];

    scanf("%d", &n);
    scanf("%s", input);

    max = -1;
    count = 0;
    idx = 0;

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            msgLength[idx++] = ++count;
            if (count > max)
                max = count;
            i++;
            count = 0;
        }
        else
            count++;
    }

    if (max > n)
        printf("Impossible\n");
    else
    {
        ans = 0;
        for (i = 0; i < idx; i++)
        {
            int l = msgLength[i];
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n)
            {
                l += msgLength[i + 1] + 1;
                i++;
            }
            ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}

