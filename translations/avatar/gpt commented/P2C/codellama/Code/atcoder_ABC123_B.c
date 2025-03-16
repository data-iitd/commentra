
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int menu[5][2];  // Declare a 2D array to store menu items
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop to collect 5 menu items from user input
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &menu[i][0]);  // Take input from the user
        menu[i][1] = menu[i][0] % 10;  // Extract the last digit of the input and store it in the second element of the sublist
        if (menu[i][1] == 0)  // If the last digit is 0
            menu[i][1] = 10;  // Change it to 10 (to avoid zero as a value)
    }

    // Sort the menu based on the second element (e) of each sublist
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (menu[i][1] > menu[j][1])
            {
                for (k = 0; k < 2; k++)
                {
                    l = menu[i][k];
                    menu[i][k] = menu[j][k];
                    menu[j][k] = l;
                }
            }
        }
    }

    // Loop through the sorted menu starting from the second item
    for (i = 1; i < 5; i++)
    {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += (menu[i][0] / 10) + 1;
    }

    // Print the total cost, including the first item's original value
    printf("%d", ans + menu[0][0]);  // Add the first item's value to the accumulated cost and print the result

    return 0;
}

