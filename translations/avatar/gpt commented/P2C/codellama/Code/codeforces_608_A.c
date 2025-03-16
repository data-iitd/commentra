
#include <stdio.h>

int main()
{
    // Read the number of intervals (n) and the starting point (s)
    int n, s;
    scanf("%d %d", &n, &s);

    // Initialize a variable to keep track of the maximum additional distance (c)
    int c = 0;

    // Iterate over each interval
    for (int i = 0; i < n; i++)
    {
        // Read the start (f) and end (t) of the interval
        int f, t;
        scanf("%d %d", &f, &t);

        // Calculate the additional distance that can be covered
        int x = t - (s - f);

        // Update the maximum additional distance if the current one is greater
        if (x > c)
        {
            c = x;
        }
    }

    // Output the total distance covered, which is the starting point plus the maximum additional distance
    printf("%d\n", s + c);

    return 0;
}

