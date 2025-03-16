
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    // Step 3: Create a Scanner object to read input from the user
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    // Step 4: Read the values of n, a, and b
    int list1[a];
    int list2[b];

    // Step 5: Create two ArrayList objects to store the lists of integers
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &list1[i]);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &list2[i]);
    }

    // Step 6: Read the elements of list1 and list2 from the user
    for (int i = 0; i < n; i++)
    {
        if (list1[i] == i + 1)
        {
            printf("%d ", 1);
        }
        else
        {
            printf("%d ", 2);
        }
    }

    // Step 7: Iterate through the range from 1 to n and print the appropriate list number
    return 0;
}

