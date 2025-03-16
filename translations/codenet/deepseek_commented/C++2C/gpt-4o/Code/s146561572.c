#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200010
#define MAX_K 2000010
#define MOD 1000000007
#define INF 1000000005
#define INF64 2000000000000000000LL

// Function to solve the problem
void solve() {
    long long ans = 0; // Initialize the answer variable
    int n; 
    scanf("%d", &n); // Read the number of nodes

    // Calculate the contribution of each node to the answer
    for (int i = 1; i <= n; i++) {
        ans += i * 1LL * (n - i + 1); // Contribution of node i
    }

    // Adjust the answer based on the edges between nodes
    for (int i = 1; i < n; i++) {
        int u, v; 
        scanf("%d %d", &u, &v); // Read the edge connecting nodes u and v
        int a = u > v ? u : v; // Determine the maximum node
        int b = u < v ? u : v; // Determine the minimum node
        ans -= b * 1LL * (n - a + 1); // Subtract the contribution of the edge
    }

    // Output the final answer
    printf("%lld\n", ans);
}

int main() {
<<<<<<< HEAD
    // Enable fast input/output (not needed in C, but we can optimize if necessary)

    int t; // Variable to hold the number of test cases
=======
    // Uncomment the following lines for file input/output during local testing
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t; // Variable to hold the number of test cases
    // scanf("%d", &t); // Uncomment to read the number of test cases
>>>>>>> 98c87cb78a (data updated)
    t = 1; // For now, we will just run one test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }
    return 0; // Return success
}

// <END-OF-CODE>
