#######
# Code
#######

# Include header files
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int n, m, i, ind, mx;

    // Read the number of elements 'n' and the modulus 'm'
    scanf("%d %d", &n, &m);

    // Declare an array 'l' to store the elements
    int l[n];

    // Read the elements of the array 'l'
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }

    // Declare an array 'l2' to store the quotients of each element in 'l' divided by 'm'
    int l2[n];

    // Iterate through each element 'i' in the array 'l'
    for (i = 0; i < n; i++)
    {
        // Check if the element 'i' is divisible by 'm'. If yes, store the quotient (integer division) in 'l2'. If not, store the quotient plus one.
        if (l[i] % m == 0)
        {
            l2[i] = l[i] / m;
        }
        else
        {
            l2[i] = l[i] / m + 1;
        }
    }

    // Find the maximum quotient in 'l2'
    mx = l2[0];
    for (i = 1; i < n; i++)
    {
        if (l2[i] > mx)
        {
            mx = l2[i];
        }
    }

    // Iterate through each index 'i' from 0 to 'n-1' in the array 'l2'
    for (i = 0; i < n; i++)
    {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'. If yes, store the index 'i' in the variable 'ind'.
        if (l2[i] == mx)
        {
            ind = i;
        }
    }

    // Print the index 'ind' plus one (since the indices in C start from 0)
    printf("%d\n", ind + 1);

    return 0;
}

