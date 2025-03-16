
#include <stdio.h>
#include <limits.h>

int main()
{
    // Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
    int n, m, x;
    // Initialize an array to keep track of the presence of numbers (size 105 to accommodate possible values)
    int a[105] = {};
    
    // Read the values of n, m, and x from standard input
    scanf("%d %d %d", &n, &m, &x);

    // Read m numbers from input and mark their presence in the array 'a'
    for(int i = 0; i < m; ++i)
    {
        int temp;
        // Read a number and set the corresponding index in array 'a' to 1
        scanf("%d", &temp);
        a[temp] = 1;
    }

    // Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
    int ansl = 0, ansr = 0, i;

    // Count how many numbers are present from x to n (right side)
    for(i = x; i <= n; ++i)
    {
        ansr += a[i]; // Increment ansr if a[i] is 1 (indicating presence)
    }

    // Count how many numbers are present from x to 0 (left side)
    for(i = x; i >= 0; --i)
    {
        ansl += a[i]; // Increment ansl if a[i] is 1 (indicating presence)
    }

    // Output the minimum of the counts from both sides
    printf("%d\n", (ansl < ansr)? ansl : ansr);
    
    // Return 0 to indicate successful completion of the program
    return 0;
}


