#######
# Code
#######

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize the number of test cases
    int n;
    scanf("%d", &n);

    // Initialize a list 'l' of size 1000010 with zeros
    int *l = (int *)malloc(sizeof(int) * 1000010);
    for (int i = 0; i < 1000010; i++)
    {
        l[i] = 0;
    }

    // Initialize a list 'dp' of size 1000010 with zeros
    int *dp = (int *)malloc(sizeof(int) * 1000010);
    for (int i = 0; i < 1000010; i++)
    {
        dp[i] = 0;
    }

    // Read input for 'n' test cases
    for (int i = 0; i < n; i++)
    {
        // Read two integers 'a' and 'b' as input
        int a, b;
        scanf("%d %d", &a, &b);
        // Assign value 'b' to index 'a' in list 'l'
        l[a] = b;
    }

    // Check if the first element of the list 'l' is positive
    if (l[0] > 0)
    {
        // Set the first element of 'dp' to 1
        dp[0] = 1;
    }

    // Initialize a variable'mx' to keep track of the maximum length of a subsequence
    int mx = 0;

    // Iterate through the list 'l' from index 1 to 1000010
    for (int i = 1; i < 1000010; i++)
    {
        // If the current element of 'l' is zero, set the corresponding element of 'dp' to the previous element
        if (l[i] == 0)
        {
            dp[i] = dp[i - 1];
        }
        // If the current element of 'l' is greater than or equal to 'i', set the corresponding element of 'dp' to 1
        // This indicates that the current element is part of a subsequence of length 'i'
        else if (l[i] >= i)
        {
            dp[i] = 1;
        }
        // If the current element of 'l' is less than 'i', calculate the length of the longest subsequence ending at 'i - l[i] - 1'
        // and add 1 to get the length of the subsequence ending at 'i'
        else
        {
            dp[i] = dp[i - l[i] - 1] + 1;
        }
        // Update the maximum length of a subsequence if a longer one is found
        if (dp[i] > mx)
        {
            mx = dp[i];
        }
    }

    // Print the answer, which is the number of elements in the longest subsequence that is not a subsequence of the given sequence
    printf("%d\n", n - mx);

    return 0;
}

