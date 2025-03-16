#include <stdio.h>

int main()
{
    // Read the number of events (n) and the starting time (s)
    int n, s;
    scanf("%d %d", &n, &s);

    // Initialize the maximum additional time to 0
    int c = 0;

    // Loop through each event
    for (int i = 0; i < n; i++)
    {
        // Read the finish time (f) and the time taken (t) for the current event
        int f, t;
        scanf("%d %d", &f, &t);

        // Calculate the additional time required if the event starts at time s
        int x = t - (s - f);

        // Update the maximum additional time if the current event requires more time
        if (x > c)
            c = x;
    }

    // Print the total time including the maximum additional time
    printf("%d\n", s + c);

    return 0;
}

