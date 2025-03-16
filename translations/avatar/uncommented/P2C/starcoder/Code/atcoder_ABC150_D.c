#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n, num;
    scanf("%d %d", &n, &num);
    int num_set[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num_set[i]);
    }
    int two_times_set[30];
    for (int i = 0; i < 30; i++)
    {
        two_times_set[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            num_set[i] /= 2;
            if (num_set[i] % 2!= 0)
            {
                two_times_set[j] = 1;
                break;
            }
        }
        if (two_times_set[0] == 1 && two_times_set[1] == 1)
        {
            printf("0\n");
            return 0;
        }
    }
    int num_list[n];
    for (int i = 0; i < n; i++)
    {
        num_list[i] = num_set[i];
    }
    int lcm = num_list[0];
    for (int i = 1; i < n; i++)
    {
        lcm = lcm * num_list[i] / __gcd(lcm, num_list[i]);
    }
    printf("%d\n", (num - lcm / 2) / lcm + 1);
    return 0;
}

