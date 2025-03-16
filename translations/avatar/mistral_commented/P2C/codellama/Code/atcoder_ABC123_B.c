#include <stdio.h>
#include <math.h>

int main()
{
    // Initialize an empty list called menu
    int menu[5][2];
    int i, j, k, m, e, ans;

    // Use a for loop to iterate 5 times
    for (i = 0; i < 5; i++)
    {
        // Take user input and assign it to the variable m
        scanf("%d", &m);

        // Extract the last character of the string m to determine the exponent e
        e = m % 10;

        // If e is 0, set it to 10
        if (e == 0)
            e = 10;

        // Append a list containing the integer value of m and the exponent e to the menu list
        menu[i][0] = m;
        menu[i][1] = e;
    }

    // Sort the menu list based on the exponent value using the sort() method with a lambda function as the key
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (menu[i][1] > menu[j][1])
            {
                for (k = 0; k < 2; k++)
                {
                    m = menu[i][k];
                    menu[i][k] = menu[j][k];
                    menu[j][k] = m;
                }
            }
        }
    }

    // Initialize a variable called ans to 0
    ans = 0;

    // Use a for loop to iterate through the menu list starting from the second element (index 1)
    for (i = 1; i < 5; i++)
    {
        // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up using the ceil() function from the math module
        num_full_10s = ceil(menu[i][0] / 10);

        // Multiply this value by 10 and add it to the ans variable
        ans += num_full_10s * 10;
    }

    // Finally, print the sum of the first element in the menu list (which is the initial number) and the value of ans
    printf("%d\n", menu[0][0] + ans);

    return 0;
}

