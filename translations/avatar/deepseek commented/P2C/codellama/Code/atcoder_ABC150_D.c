
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Read the input values for n and num
    int n, num;
    scanf("%d %d", &n, &num);

    // Read the set of integers
    int num_set[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num_set[i]);
    }

    // Initialize an empty set to store the number of times each integer is divisible by 2
    int two_times_set[n];
    for (int i = 0; i < n; i++)
    {
        two_times_set[i] = 0;
    }

    // Loop through each integer in the num_set
    for (int i = 0; i < n; i++)
    {
        // Divide the integer by 2 repeatedly until it is no longer even
        for (int j = 1; j < 30; j++)
        {
            num_set[i] /= 2;
            if (num_set[i] % 2 != 0)
            {
                // Add the count to two_times_set
                two_times_set[i] = j;
                break;
            }
        }
        // If two_times_set contains more than one element, print 0 and break
        if (two_times_set[i] != 1)
        {
            printf("0\n");
            break;
        }
    }
    else
    {
        // If the loop completes, calculate the LCM of the integers in num_set
        int lcm = num_set[0];
        for (int i = 1; i < n; i++)
        {
            lcm = lcm * num_set[i] / (int)gcd(lcm, num_set[i]);
        }

        // Calculate the number of integers in the range from 1 to num that are divisible by the LCM
        printf("%d\n", (num - lcm / 2) / lcm + 1);
    }

    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

