
#include <bits/stdc++.h>
using namespace std;

int dfs ( vector < set < int > > & links, int n, int k, int v, int p ) {  // Step 2: Define the DFS function
    int height_from_leaf = 0;  // Initialize the height from the leaf node
    int cut_count = 0;  // Initialize the count of cuts
    for ( int u : links [ v ] ) {  // Step 3: Traverse the tree
        if ( u == 0 ) {  // Skip if the node is the root (0)
            continue;
        }
        int hgt, cut = dfs ( links, n, k, u, v );  // Recursively call DFS
        height_from_leaf = max ( height_from_leaf, hgt );  // Update the height from the leaf
        cut_count += cut;  // Count the number of cuts
    }
    height_from_leaf += 1;  // Increment the height from the leaf node
    if ( p!= 0 && height_from_leaf == k ) {  // Step 4: Check if a cut is needed
        height_from_leaf = 0;  // Reset the height
        cut_count += 1;  // Increment the cut count
    }
    return height_from_leaf, cut_count;  // Step 5: Return the height and cut count
}

int main ( ) {
    int n, k;  // Step 6: Read input data
    cin >> n >> k;
    vector < set < int > > links ( n );  // Initialize the tree structure
    for ( int i = 0 ; i < n ; i ++ ) {
        int a;
        cin >> a;
        a -= 1;
        links [ a ].insert ( i );
    }
    int ans = dfs ( links, n, k, 0, 0 );  // Step 8: Perform DFS starting from the root
    if ( links [ 0 ].size ( )!= 1 ) {  // Step 9: Adjust the answer if necessary
        ans += 1;
    }
    cout << ans << endl;  // Step 10: Output the final result
    return 0;
}

