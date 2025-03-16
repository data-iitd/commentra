
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Take input from the user
    scanf("%d", &n);
    // Read the input, split it into a list of integers, and store it in 'a'
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // Sort the list 'a'
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < n; i++)
    {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2)
        {
            // If the condition is met, return 'YES'
            printf("YES");
            return 0;
        }
    }
    // If the loop completes without finding a match, return 'NO'
    printf("NO");
    return 0;
}

