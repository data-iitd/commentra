#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to cut the ribbon
void cutRibbon()
{
    // Declare variables
    int length, arr[3], i, j, k, ans;
    
    // Read input and convert it into a list of integers
    scanf("%d %d %d %d", &length, &arr[0], &arr[1], &arr[2]);
    
    // Sort the next three elements (the lengths of the pieces) in ascending order
    arr[0] = arr[0] < arr[1] ? arr[0] : arr[1];
    arr[1] = arr[0] < arr[1] ? arr[1] : arr[0];
    arr[2] = arr[2] < arr[1] ? arr[2] : arr[1];
    arr[1] = arr[2] < arr[1] ? arr[1] : arr[2];
    
    // If the total length is divisible by the smallest piece length, print the maximum number of pieces
    if (length % arr[0] == 0)
    {
        printf("%d\n", length / arr[0]);
        return;
    }
    
    // Initialize the answer variable to keep track of the maximum pieces
    ans = 0;
    
    // Case when the two smallest piece lengths are equal
    if (arr[0] == arr[1])
    {
        k = 0;
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for (i = 0; i <= length / arr[2]; i++)
        {
            // Calculate the remaining length after using i pieces of the largest size
            check = length - i * arr[2];
            // Check if the remaining length can be completely divided by the smallest piece length
            if (check >= 0 && check % arr[0] == 0)
            {
                k = check / arr[0];
                // Update the maximum pieces found
                ans = ans > k + i ? ans : k + i;
            }
        }
    }
    else
    {
        // Case when the two smallest piece lengths are different
        k = 0;
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for (i = 0; i <= length / arr[2]; i++)
        {
            // Iterate through the number of the second largest pieces that can fit into the ribbon
            for (j = 0; j <= length / arr[1]; j++)
            {
                // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                check = length - i * arr[2] - j * arr[1];
                // Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 && check % arr[0] == 0)
                {
                    k = check / arr[0];
                    // Update the maximum pieces found
                    ans = ans > k + i + j ? ans : k + i + j;
                }
            }
        }
    }
    
    // Print the maximum number of pieces that can be obtained
    printf("%d\n", ans);
    return;
}

// Call the function to execute the ribbon cutting logic
int main()
{
    cutRibbon();
    return 0;
}

