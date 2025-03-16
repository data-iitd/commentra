#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, x;
    int a[105] = {0}; // Initialize array to keep track of positions
    scanf("%d %d %d", &n, &m, &x); // Read the values of n, m, and x

    for(int i = 0; i < m; ++i)
    {
        int temp;
        scanf("%d", &temp); // Read the positions to be marked
        a[temp] = 1; // Mark the positions in array a
    }

    int ansl = 0, ansr = 0; // Initialize variables to store distances
    for(int i = x; i <= n; ++i) // Calculate the number of marked positions to the right of x
    {
        ansr += a[i];
    }
    for(int i = x; i >= 0; --i) // Calculate the number of marked positions to the left of x
    {
        ansl += a[i];
    }

    printf("%d\n", (ansl < ansr) ? ansl : ansr); // Print the minimum of the left and right distances
    return 0;
}
