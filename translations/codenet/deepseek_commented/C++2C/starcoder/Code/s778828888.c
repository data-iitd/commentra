#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n, m, x;
    int a[105] = {}; // Step 2: Initialize array to keep track of positions
    scanf("%d %d %d", &n, &m, &x); // Step 1: Read the values of n, m, and x

    for(int i = 0; i < m; ++i)
    {
        int temp;
        scanf("%d", &temp); // Read the positions to be marked
        a[temp] = 1; // Step 3: Mark the positions in array a
    }

    int ansl = 0, ansr = 0, i; // Initialize variables to store distances
    for(i = x; i <= n; ++i) // Step 4: Calculate the number of marked positions to the right of x
    {
        ansr += a[i];
    }
    for(i=x; i >= 0; --i) // Calculate the number of marked positions to the left of x
    {
        ansl += a[i];
    }

    printf("%d\n", std::min(ansl, ansr)); // Step 5: Print the minimum of the left and right distances
    return 0;
}
