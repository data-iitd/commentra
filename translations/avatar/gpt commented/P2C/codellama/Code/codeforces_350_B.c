#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, x, cnt[100001], t[100001], a[100001], ans[100001];

    // Read the number of elements
    scanf("%d", &n);

    // Read the list 't' and prepend a 0 for 1-based indexing
    t[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
    }

    // Read the list 'a' and prepend a 0 for 1-based indexing
    a[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Initialize the answer list and a count list to track occurrences
    for (i = 0; i <= n; i++)
    {
        ans[i] = 0;
        cnt[i] = 0;
    }

    // Count the occurrences of each element in list 'a'
    for (i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (i = 1; i <= n; i++)
    {
        // Check if the current element in 't' is 1
        if (t[i] == 1)
        {
            // Initialize a current path list starting with the current index
            int crt[100001];
            crt[0] = i;
            x = a[i];

            // Continue to follow the chain while the count of x is 1
            while (cnt[x] == 1)
            {
                crt[crt[0]] = x;  // Add x to the current path
                x = a[x];         // Move to the next index in the chain
            }

            // Update the answer if the current path is longer than the previous answer
            if (crt[0] > ans[0])
            {
                for (j = 0; j <= crt[0]; j++)
                {
                    ans[j] = crt[j];  // Store a copy of the current path
                }
            }
        }
    }

    // Reverse the answer list to maintain the original order
    for (i = 0; i < ans[0] / 2; i++)
    {
        int temp = ans[i];
        ans[i] = ans[ans[0] - i];
        ans[ans[0] - i] = temp;
    }

    // Print the length of the longest path found
    printf("%d\n", ans[0]);

    // Print the elements of the longest path as a space-separated string
    for (i = 1; i <= ans[0]; i++)
    {
        printf("%d ", ans[i]);
    }

    // End with comment "