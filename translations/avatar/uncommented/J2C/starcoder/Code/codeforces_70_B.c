#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char input[100000];
    scanf("%s", input);
    int max = -1;
    int msgLength[100000];
    int count = 0;
    int idx = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];
        if (c == '.' || c == '?' || c == '!')
        {
            msgLength[idx++] = ++count;
            if (count > max) max = count;
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
        int ans = 0;
        for (int i = 0; i < idx; i++)
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
