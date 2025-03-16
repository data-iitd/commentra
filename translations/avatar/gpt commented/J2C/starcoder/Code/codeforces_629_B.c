#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, a, b, answer = 0, MfriendPerDay[367], FfriendPerDay[367];
    char c;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &c);
        scanf("%d", &a);
        scanf("%d", &b);
        for (j = a; j <= b; j++)
        {
            if (c == 'M')
                MfriendPerDay[j]++;
            else
                FfriendPerDay[j]++;
            if (MfriendPerDay[j] < FfriendPerDay[j])
            {
                if (MfriendPerDay[j] > answer)
                    answer = MfriendPerDay[j];
            }
            else
            {
                if (FfriendPerDay[j] > answer)
                    answer = FfriendPerDay[j];
            }
        }
    }
    printf("%d\n", answer * 2);
    return 0;
}

