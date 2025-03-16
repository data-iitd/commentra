#include <stdio.h>

int main()
{
    int n, i, last, ans;

    // Read the number of elements from user input
    scanf("%d", &n);

    // Initialize an empty list to store the elements
    int l[n];

    // Loop to read 'n' integers from user input and append them to the list
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }

    // Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
    ans = n - 1;

    // Initialize a variable to keep track of the last element processed
    last = 0;

    // Loop through each element in the list
    for (i = 0; i < n; i++)
    {
        // Calculate the distance from the last element to the current element
        // and add 1 for the step to the current element
        ans += abs(last - l[i]) + 1;

        // Update 'last' to the current element for the next iteration
        last = l[i];
    }

    // Print the final calculated answer
    printf("%d\n", ans);

    return 0;
}

