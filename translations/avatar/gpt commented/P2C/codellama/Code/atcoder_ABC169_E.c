#include <stdio.h>

int main()
{
    // Read the number of intervals
    int n;
    scanf("%d", &n);

    // Initialize lists to store the lower and upper bounds of the intervals
    int low[n];
    int high[n];

    // Read each interval and store the lower and upper bounds
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &low[i], &high[i]);
    }

    // Sort the lower and upper bounds
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (low[i] > low[j])
            {
                int temp = low[i];
                low[i] = low[j];
                low[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (high[i] > high[j])
            {
                int temp = high[i];
                high[i] = high[j];
                high[j] = temp;
            }
        }
    }

    // Check if the number of intervals is odd
    if (n % 2)
    {
        // For odd number of intervals, calculate the range of the median interval
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    }
    else
    {
        // For even number of intervals, calculate the average of the two middle values
        int hh = (high[n / 2 - 1] + high[n / 2]) / 2;  // Average of the two middle high values
        int ll = (low[n / 2 - 1] + low[n / 2]) / 2;     // Average of the two middle low values
        // Calculate the range and print the result
        printf("%d\n", (hh - ll) * 2 + 1);
    }

    return 0;
}

