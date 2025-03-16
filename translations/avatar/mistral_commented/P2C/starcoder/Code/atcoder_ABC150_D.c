#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, num;
    scanf("%d %d", &n, &num);
    int num_set[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &num_set[i]);
    }
    int two_times_set[num];
    for (int i = 0; i < num; i++)
    {
        int power_of_two = 0;
        int i_copy = num_set[i];
        while (i_copy % 2 == 0)
        {
            power_of_two++;
            i_copy /= 2;
        }
        if (power_of_two > 1)
        {
            printf("0\n");
            exit(0);
        }
        two_times_set[i] = power_of_two;
    }
    if (num!= 1)
    {
        printf("0\n");
        exit(0);
    }
    int lcm = num_set[0];
    for (int i = 1; i < num; i++)
    {
        lcm = lcm * num_set[i] / __gcd(lcm, num_set[i]);
    }
    printf("%d\n", (num - lcm / 2) / lcm + 1);
    return 0;
}

