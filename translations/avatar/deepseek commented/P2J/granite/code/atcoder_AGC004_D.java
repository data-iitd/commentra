

import java.io.*;
import java.util.*;

class atcoder_AGC004_D {
    static int dfs ( int[][] links, int n, int k, int v, int p ) {  // Step 1: Define the DFS function
        int height_from_leaf = 0;  // Initialize the height from the leaf node
        int cut_count = 0;  // Initialize the count of cuts
        for ( int u : links [ v ] ) {  // Step 2: Traverse the tree
            if ( u == 0 ) {  // Skip if the node is the root (0)
                continue;
            }
            int hgt = dfs ( links, n, k, u, v );  // Recursively call DFS
            height_from_leaf = Math.max ( height_from_leaf, hgt );  // Update the height from the leaf
            cut_count += hgt;  // Count the number of cuts
        }
        height_from_leaf += 1;  // Increment the height from the leaf node
        if ( p!= 0 && height_from_leaf == k ) {  // Step 3: Check if a cut is needed
            height_from_leaf = 0;  // Reset the height
            cut_count += 1;  // Increment the cut count
        }
        return height_from_leaf;  // Step 4: Return the height
    }

    public static void main ( String[] args ) throws IOException {  // Step 5: Read input data
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
        String[] s = br.readLine ( ).split ( " " );
        int n = Integer.parseInt ( s [ 0 ] );
        int k = Integer.parseInt ( s [ 1 ] );
        int[][] links = new int [ n ] [ ];
        for ( int i = 0 ; i < n ; i++ ) {
            s = br.readLine ( ).split ( " " );
            int a = Integer.parseInt ( s [ 0 ] );
            links [ i ] = new int [ a - 1 ];
            for ( int j = 0 ; j < a - 1 ; j++ ) {
                links [ i ] [ j ] = Integer.parseInt ( s [ j + 1 ] ) - 1;
            }
        }
        int ans = dfs ( links, n, k, 0, 0 );  // Step 6: Perform DFS starting from the root
        if ( Integer.parseInt ( s [ 0 ] )!= 1 ) {  // Step 7: Adjust the answer if necessary
            ans += 1;
        }
        System.out.println ( ans );  // Step 8: Output the final result
    }
}

Translate the above Java code to C++ and end with comment "