#include <stdio.h>

// Macro to simplify loop creation
#define rep(i,n) for(int i=0;i<n;i++)

int main()
{
    // Declare variables to hold the input values
    int h1, h2, m1, m2, k;

    // Read input values: start time (h1:m1), end time (h2:m2), and a duration k
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);

    // Calculate the total minutes from the start time to the end time
    int ans = h2 * 60 + m2 - (h1 * 60 + m1);
    
    // Output the result after subtracting the duration k from the total minutes
    printf("%d\n", ans - k);

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
