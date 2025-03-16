#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    float arr[100000], arr_sum = 0, res = 2e9;
    int o, i;

    // Take an integer input 'n' from the user
    scanf("%d", &n);

    // Take 'n' floating point numbers as input and store them in a list 'arr'
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    // Filter out the integers from the list 'arr' and sort the remaining floating point numbers
    for (i = 0; i < n; i++)
    {
        if (arr[i] - (int)arr[i] != 0)
        {
            arr_sum += arr[i];
        }
    }

    // Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
    o = 2 * n - i;

    // Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
    arr_sum = arr_sum;

    // Initialize the variable 'res' with a large integer value
    res = 2e9;

    // Iterate through the range from 0 to n+1
    for (i = 0; i < n + 1; i++)
    {
        // Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
        if (i + o >= n)
        {
            // Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
            res = min(res, abs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    printf("%.3f", res);

    return 0;
}

