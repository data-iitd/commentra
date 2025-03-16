#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the binary index of a number in the list
int bis(int x, int y)
{
    // Base case: if y is one more than x, return y
    if (y == x + 1)
        return y;

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible((x + y) / 2))
        return bis(x, (x + y) / 2);

    // If is_possible returns False for (x + y) / 2 and y, return the binary index of y
    else
        return bis((x + y) / 2, y);
}

// Function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
int is_possible(int K)
{
    // Initializing an empty list to store the indices and values of the elements in the list
    int dp[100000];
    dp[0] = A[0];

    // Iterating through the list starting from the second element
    for (int i = 1; i < N; i++)
    {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (A[i] <= dp[i - 1])
        {
            int j = i - 1;
            while (j >= 0 && dp[j] > A[i])
                j--;
            dp[j + 1] = A[i];
        }

        // Adding the current element to the dp list
        dp[i] = A[i];

        // Initializing a flag to check if we need to add an element to the dp list
        int is_added = 0;

        // Iterating through the dp list from the end to the beginning
        for (int j = i; j >= 0; j--)
        {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp[j] < A[i] && dp[j + 1] < K - 1)
            {
                dp[j + 1] = A[i];
                is_added = 1;
                break;
            }
        }

        // If we didn't add an element to the dp list, the current number can't be added
        if (!is_added)
            return 0;
    }

    // Returning 1 if the list is possible
    return 1;
}

// Driver code
int main()
{
    // Taking input from user and converting it into a list of integers
    char input[100000];
    scanf("%s", input);
    int A[100000];
    int N = 0;
    for (int i = 0; input[i]; i++)
    {
        if (input[i] =='')
            continue;
        A[N++] = input[i] - '0';
    }

    // Adding the first element of the list to the beginning of the list
    // to make the first index 0 based instead of 1 based
    A[N] = A[0];
    for (int i = 0; i < N; i++)
        A[i + 1] = A[i];

    // Assigning the length of the list to a variable for easier reference
    N++;

    // Printing the result of the binary index function
    printf("%d\n", bis(0, N));

    return 0;
}

