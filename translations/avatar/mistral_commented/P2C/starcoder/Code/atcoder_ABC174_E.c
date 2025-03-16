#include <stdio.h>
#include <stdlib.h>

// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
int check(int lis[], int n, int k, int mid)
{
    // Iterate through each element in the list 'lis'
    for (int i = 0; i < n; i++)
    {
        // If the element 'i' is divisible by'mid', increment 'k'
        if (lis[i] % mid == 0)
            k += 1;
        // Subtract the quotient of 'i' and'mid' from 'k'
        k -= (lis[i] / mid);
    }
    // Return True if 'k' is still positive after the loop, else False
    return k >= 0;
}

// Function to find the answer
int find(int lis[], int n, int k)
{
    // Initialize the variables 'a' and 'b' with minimum and maximum values respectively
    int a = 1, b = lis[n - 1];

    // Initialize the variable 'ans' with the maximum value of 'b'
    int ans = b;

    // Binary search algorithm to find the answer
    while (a <= b)
    {
        // Calculate the middle value of 'a' and 'b'
        int mid = (a + b) / 2;
        // Check if 'k' is positive after checking all elements in 'lis' with'mid' as divisor
        if (check(lis, n, k, mid))
        {
            // Update the answer if the condition is true
            ans = mid;
            // Update the upper limit of the binary search 'b'
            b = mid - 1;
        }
        else
        {
            // Update the lower limit of the binary search 'a'
            a = mid + 1;
        }
    }
    // Return the answer
    return ans;
}

// Driver code
int main()
{
    // Take input of 'n' and 'k'
    int n, k;
    scanf("%d %d", &n, &k);

    // Take input of 'n' number of elements in the list 'lis' and store them in a list
    int lis[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &lis[i]);

    // Find the answer
    int ans = find(lis, n, k);

    // Print the answer
    printf("%d", ans);

    return 0;
}

