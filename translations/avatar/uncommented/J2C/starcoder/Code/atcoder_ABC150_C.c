#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, i, j, k, sum = 0;
    char number[1000000], line[2][1000000];
    scanf("%d", &n);
    for (i = 0; i < 2; i++)
        scanf("%s", line[i]);
    for (i = 1; i <= n; i++)
        number[i - 1] = i + '0';
    number[n] = '\0';
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (line[0][i] == number[j] && line[1][i] == number[k])
                {
                    if (sum == 0)
                        sum = j - k;
                    else
                        sum = j - k - sum;
                }
            }
        }
    }
    printf("%d\n", abs(sum));
    return 0;
}

