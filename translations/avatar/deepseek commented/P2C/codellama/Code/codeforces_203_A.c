
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char xxs[100];
    int x, t, a, b, da, db;

    // Get the input
    scanf("%s", xxs);

    // Split the input into individual variables
    sscanf(xxs, "%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    // Define the main function to perform the logic
    char *main()
    {
        // Check if the value of x is 0
        if (x == 0)
        {
            printf("YES\n");
            return "Result Found";
        }

        // Calculate the maximum number of times a and b can be decremented within the time limit t
        int a_time = (a / da) < (t - 1) ? (a / da) : (t - 1);
        int b_time = (b / db) < (t - 1) ? (b / db) : (t - 1);

        // Iterate over all possible combinations of decrements for a and b within their respective limits
        for (int i = 0; i <= a_time; i++)
        {
            for (int j = 0; j <= b_time; j++)
            {
                // Check if either a or b (or their sum) equals x
                if (a - da * i == x || b - db * j == x)
                {
                    printf("YES\n");
                    return "Result Found";
                }
                if ((a - da * i) + (b - db * j) == x)
                {
                    printf("YES\n");
                    return "Result Found";
                }
            }
        }

        // Return "Result Not Found" if no combination results in x
        return "Result Not Found";
    }

    // Call the main function and store the result
    char *ff = main();

    // Check the result and print "NO" if the result is "Result Not Found"
    if (strcmp(ff, "Result Not Found") == 0)
    {
        printf("NO\n");
    }

    return 0;
}

