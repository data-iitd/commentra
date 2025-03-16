#include <stdio.h>

int main()
{
    // Read the number of pairs
    int n;
    scanf("%d", &n);
    
    // Initialize lists to store the lower and higher values of each pair
    int low[n];
    int high[n];
    
    // Loop to read each pair and append values to the lists
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &low[i], &high[i]);
    }
    
    // Sort the lists
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
    
    // Check if the number of pairs is odd or even
    if (n % 2)
    {
        // If odd, calculate the range between the middle elements
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    }
    else
    {
        // If even, calculate the average of the middle elements and print the range
        int hh = (high[(n) / 2 - 1] + high[(n) / 2]) / 2;
        int ll = (low[(n) / 2 - 1] + low[(n) / 2]) / 2;
        printf("%d\n", (hh - ll) * 2 + 1);
    }
    
    return 0;
}

