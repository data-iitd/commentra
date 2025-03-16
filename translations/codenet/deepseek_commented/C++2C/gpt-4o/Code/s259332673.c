#include <stdio.h>

#define rep(i,n) for(int i=0;i<n;i++)

int main()
{
    // Declare integer variables to store input values
    int h1, h2, m1, m2, k;
    
    // Read input values for h1, m1, h2, m2, and k from the standard input
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
    
    // Calculate the difference in minutes between h2:m2 and h1:m1
    int ans = (h2 * 60 + m2) - (h1 * 60 + m1);
    
    // Print the result of subtracting k from the calculated difference
    printf("%d\n", ans - k);
    
    return 0;
}

// <END-OF-CODE>
