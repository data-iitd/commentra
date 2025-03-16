
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char k[100], n[100], w[100];
    // Declaring variables
    scanf("%s %s %s", k, n, w);
    // Taking input for k, n, and w
    if (1 <= atoi(k) && atoi(w) <= 1000)
    {
        // Checking if k and w are within the specified range
        int total = 0;
        // Initializing total to 0
        for (int i = 1; i <= atoi(w); i++)
        {
            // Looping from 1 to w (inclusive)
            total += i * atoi(k);
            // Multiplying the current iteration number by k and adding to total
        }
        if (total > atoi(n))
        {
            // Checking if total is greater than n
            printf("%d", total - atoi(n));
            // Printing the difference between total and n if total is greater
        }
        else
        {
            printf("0");
            // Printing 0 if total is not greater than n
        }
    }
    return 0;
}

