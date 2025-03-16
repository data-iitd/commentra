#include <stdio.h>

int main()
{
    int n, i, mx, arr[1000], ans[1000];

    // Read the number of elements in the array
    scanf("%d", &n);

    // Read the array elements from input, converting them to integers
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Initialize an answer array with zeros, which will store the results
    for (i = 0; i < n; i++)
        ans[i] = 0;

    // Set the maximum value to the last element of the array
    mx = arr[n - 1];

    // Iterate through the array from the second last element to the first
    for (i = n - 2; i >= 0; i--)
    {
        // Calculate the required value for ans[i] based on the difference from the maximum
        ans[i] = max(0, mx - arr[i] + 1);

        // Update the maximum value if the current element is greater than the current maximum
        if (arr[i] > mx)
            mx = arr[i];
    }

    // Print the result array as space-separated values
    for (i = 0; i < n; i++)
        printf("%d ", ans[i]);

    // End of code
    printf("\n