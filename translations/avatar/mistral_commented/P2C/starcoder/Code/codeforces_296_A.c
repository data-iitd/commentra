#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char m[n];
    scanf("%s", m);
    int possible = 1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (m[i] == m[j])
            {
                count++;
            }
        }
        if (count >= n / 2 + 1)
        {
            possible = 0;
            break;
        }
    }
    if (possible)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
