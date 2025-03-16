

#include <bits/stdc++.h>
using namespace std;

int dfs ( vector < set < int >> &links, int n, int k, int v, int p ) {  // Step 1: Define the DFS function
    int height_from_leaf = 0;  // Initialize the height from the leaf node
    int cut_count = 0;  // Initialize the count of cuts
    for ( int u : links [ v ] ) {  // Step 2: Traverse the tree
        if ( u == 0 ) {  // Skip if the node is the root (0)
            continue;
        }
        int hgt, cut = dfs ( links, n, k, u, v );  // Recursively call DFS
        height_from_leaf = max ( height_from_leaf, hgt );  // Update the height from the leaf
        cut_count += cut;  // Count the number of cuts
    }
    height_from_leaf += 1;  // Increment the height from the leaf node
    if ( p!= 0 && height_from_leaf == k ) {  // Step 3: Check if a cut is needed
        height_from_leaf = 0;  // Reset the height
        cut_count += 1;  // Increment the cut count
    }
    return height_from_leaf, cut_count;  // Step 4: Return the height and cut count
}

int main ( ) {  // Step 5: Read input data
    int n, k;
    cin >> n >> k;
    vector < set < int >> links ( n );  // Initialize the tree structure
    for ( int i = 0 ; i < n ; i ++ ) {  // Step 6: Build the tree
        int a;
        cin >> a;
        a --;
        links [ a ].insert ( i );
    }
    int _, ans = dfs ( links, n, k, 0, 0 ).second;  // Step 7: Perform DFS starting from the root
    if ( ans == 0 ) {  // Step 8: Adjust the answer if necessary
        ans = 1;
    }
    cout << ans << endl;  // Step 9: Output the final result
    return 0;
}

