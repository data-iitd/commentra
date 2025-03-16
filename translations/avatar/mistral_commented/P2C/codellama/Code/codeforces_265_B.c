#include <stdio.h>

int main()
{
    // Ask the user for the number of elements in the list
    int n;
    scanf("%d", &n);

    // Initialize an empty list to store the integers
    int l[n];

    // Iterate n times and append each integer to the list
    for (int i = 0; i < n; i++)
    {
        // Ask the user for the next integer and append it to the list
        scanf("%d", &l[i]);
    }

    // Initialize a variable to store the answer
    int ans = n - 1;

    // Initialize a variable to store the previous integer in the list
    int last = 0;

    // Iterate through each integer in the list
    for (int i = 0; i < n; i++)
    {
        // Calculate the absolute difference between the previous integer and the current integer
        // Add 1 to account for the number of steps between the two integers
        ans += abs(last - l[i]) + 1;

        // Update the value of the previous integer
        last = l[i];
    }

    // Print the value of the answer
    printf("%d\n", ans);

    return 0;
}

