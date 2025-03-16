#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    int x, t, a, b, da, db;
    int a_time, b_time;
    int i, j;
    char *result;

    // Read input values and split them into a list
    char *xxs = malloc(100 * sizeof(char));
    scanf("%s", xxs);
    char *xxs_split = strtok(xxs, " ");
    x = atoi(xxs_split);
    xxs_split = strtok(NULL, " ");
    t = atoi(xxs_split);
    xxs_split = strtok(NULL, " ");
    a = atoi(xxs_split);
    xxs_split = strtok(NULL, " ");
    b = atoi(xxs_split);
    xxs_split = strtok(NULL, " ");
    da = atoi(xxs_split);
    xxs_split = strtok(NULL, " ");
    db = atoi(xxs_split);

    // Check if the target value x is zero
    if (x == 0)
    {
        printf("YES\n");  // If x is zero, print "YES" and return
        return 0;
    }

    // Calculate the maximum time available for a and b, constrained by t
    a_time = (a / da) < (t - 1) ? (a / da) : (t - 1);
    b_time = (b / db) < (t - 1) ? (b / db) : (t - 1);

    // Iterate through all possible values of i and j within the calculated time limits
    for (i = 0; i <= a_time; i++)
    {
        for (j = 0; j <= b_time; j++)
        {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if (a - da * i == x || b - db * j == x)
            {
                printf("YES\n");  // If found, print "YES" and return
                return 0;
            }
            // Check if the sum of the remaining values of a and b equals x
            if ((a - da * i) + (b - db * j) == x)
            {
                printf("YES\n");  // If found, print "YES" and return
                return 0;
            }
        }
    }

    // If no valid combination is found, return "Result Not Found"
    printf("NO\n");
    return 0;
}

