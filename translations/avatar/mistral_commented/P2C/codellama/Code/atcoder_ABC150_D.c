#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Taking input of n and number of distinct numbers
    int n, num;
    scanf("%d %d", &n, &num);

    // Creating a set of distinct numbers
    int num_set[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &num_set[i]);
    }

    // Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
    int two_times_set[num];
    for (int i = 0; i < num; i++)
    {
        // Initializing a counter to keep track of the number of times 2 is divided
        int power_of_two = 0;

        // Dividing i by 2 repeatedly until it is no longer odd
        while (num_set[i] % 2 == 0)
        {
            power_of_two += 1;
            num_set[i] /= 2;
        }

        // If the number of times 2 is divided is not exactly 1, then the answer is 0
        if (power_of_two > 1)
        {
            printf("0\n");
            return 0;
        }

        // Add the power of 2 to two_times_set
        two_times_set[i] = power_of_two;
    }

    // If the size of two_times_set is not exactly 1, then the answer is 0
    if (num - 1 != 1)
    {
        printf("0\n");
        return 0;
    }

    // Finding the least common multiple of all numbers in num_set
    int lcm = num_set[0];

    // Finding the least common multiple of the first number and the next number
    for (int i = 1; i < num; i++)
    {
        lcm = lcm * num_set[i] / (__gcd(lcm, num_set[i]));
    }

    // Printing the answer
    printf("%d\n", (num - lcm / 2) / lcm + 1);

    return 0;
}

