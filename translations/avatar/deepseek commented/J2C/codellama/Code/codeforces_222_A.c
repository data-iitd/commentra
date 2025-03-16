
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a Scanner object to read input from the user
    int n, k, l, c, a;
    scanf("%d %d", &n, &k);

    // Initialize variables to keep track of the last number and its consecutive occurrences
    l = 0;
    c = 1;

    // Loop to read n numbers and count consecutive occurrences
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == l)
            c += 1; // Increment count if the current number is the same as the last
        else
            c = 1; // Reset count if the current number is different
        l = a; // Update the last number
    }

    // Check if the number of consecutive occurrences plus the threshold value is greater than n
    if (c + k > n)
        printf("%d", n - c); // Print the number of elements to remove
    else
        printf("-1"); // Print -1 if it's not possible to satisfy the condition

    // End of code
    printf("