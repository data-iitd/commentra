#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, ans, r[1000];

    // Ask the user for the number of elements in the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Ask the user to input the elements of the list separated by spaces
    printf("Enter the elements of the list separated by spaces: ");
    for (i = 0; i < n; i++)
        scanf("%d", &r[i]);

    // Initialize a variable to store the answer
    ans = abs(r[0]);

    // Use a for loop to calculate the sum of the absolute differences between consecutive elements
    for (i = 1; i < n; i++)
        ans += abs(r[i] - r[i-1]);

    // Print the final answer
    printf("The sum of the absolute differences between consecutive elements is: %d", ans);

    return 0;
}

