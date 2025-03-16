#include <stdio.h>
#include <string.h>

int main()
{
    // Read the input string from the user
    char soz[1000];
    scanf("%s", soz);

    // Initialize a list 'a' to store the cumulative count of consecutive characters
    // The length of 'a' is one more than the length of 'soz' to handle the base case
    int a[strlen(soz) + 1];

    // Iterate through the string to fill the cumulative count array 'a'
    for (int i = 1; i < strlen(soz); i++)
    {
        // Carry forward the previous count
        a[i] = a[i - 1];

        // If the current character is the same as the previous one, increment the count
        if (soz[i - 1] == soz[i])
        {
            a[i] += 1;
        }
    }

    // Read the number of queries from the user
    int n;
    scanf("%d", &n);

    // Initialize an empty list to store the results of each query
    int arr[n];

    // Process each query
    for (int i = 0; i < n; i++)
    {
        // Read the start and end indices for the query
        int m, l;
        scanf("%d %d", &m, &l);

        // Calculate the number of consecutive characters between indices m and l
        // and append the result to the 'arr' list
        arr[i] = a[l - 1] - a[m - 1];
    }

    // Print the results for each query
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

