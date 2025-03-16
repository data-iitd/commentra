
#include <stdio.h>

int main()
{
    // Declare variables for the number of red, green, blue items and the total number of items
    int r, g, b, n;
    
    // Input the values for red, green, blue items and total items
    scanf("%d %d %d %d", &r, &g, &b, &n);
    
    // Initialize the answer counter to zero
    int ans = 0;

    // Iterate over the possible counts of red items (i)
    for (int i = 0; i <= n / r; ++i)
    {
        // Iterate over the possible counts of green items (j)
        for (int j = 0; j <= n / g; ++j)
        {
            // Calculate the remaining items after selecting i red and j green items
            int num = n - r * i - g * j;

            // Check if the remaining items can be exactly filled with blue items
            if (num >= 0 && num % b == 0)
            {
                // If valid, increment the answer counter
                ++ans;
            }
        }
    }

    // Output the total number of valid combinations found
    printf("%d\n", ans);
    
    return 0;
}


