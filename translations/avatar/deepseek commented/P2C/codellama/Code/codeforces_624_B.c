#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Step 1: Reading the number of elements (n)
    int n;
    scanf("%d", &n);

    // Step 2: Reading the list of elements (a)
    int a[n];
    char str[100000];
    scanf("%s", str);
    char *token = strtok(str, " ");
    for (int i = 0; i < n; i++)
    {
        a[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Step 3: Initializing variables
    int pre = 1000000000;  // Initialize pre to infinity
    int ans = 0;           // Initialize ans to 0

    // Step 4: Sorting the list in descending order
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Step 5: Iterating through the list
    for (int j = 0; j < n; j++)
    {
        // Calculate the maximum value that can be added to ans
        ans += max(0, min(pre - 1, a[j]));
        // Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
        pre = max(0, min(pre - 1, a[j]));
    }

    // Step 6: Printing the result
    printf("%d\n", ans);

    return 0;
}

