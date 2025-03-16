
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to solve the problem
void solve () {
    // Initialize answer to 0
    long long ans = 0;
    
    // Read input for number of nodes n
    int n;scanf("%d",&n);
    
    // Calculate contribution of each node to the answer
    for (int i=1;i<=n;i++) {
        // Contribution of i-th node is i * (n-i+1)
        ans += i * 1ll * (n-i+1);
    }
    
    // Subtract contribution of edges
    for (int i=1;i<n;i++) {
        // Read input for two nodes u and v
        int u,v;scanf("%d%d",&u,&v);
        
        // Find maximum and minimum of u and v
        int a = max(u,v);
        int b = min(u,v);
        
        // Subtract contribution of edge (u,v) from the answer
        ans -= b * 1ll * (n-a+1);
    }
    
    // Print the answer
    printf("%lld\n",ans);
}

// Driver Code
int main () {
    // Set number of test cases to 1 for simplicity
    int t = 1;
    
    // Solve the problem for each test case
    while (t--) {
        solve();
    }
    
    return 0;
}

