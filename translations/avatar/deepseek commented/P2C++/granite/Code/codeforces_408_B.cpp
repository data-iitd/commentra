

#include <bits/stdc++.h>
using namespace std;

// Helper functions to pop and push elements from/to the heap
auto hpop = heap_pop;
auto hpush = heap_push;

int main ( ) {
    // Set the number of test cases to 1
    int t = 1;
    // Run the solution function for one test case
    for ( int _ = 0 ; _ < t ; _ ++ ) {
        // Read the first line of input and create a Counter object for the bought colors
        string line;
        cin >> line;
        unordered_map<char, int> bought_count;
        for ( char color : line ) {
            bought_count[color] += 1;
        }
        
        // Read the second line of input and create a Counter object for the colors to be made
        cin >> line;
        unordered_map<char, int> made_cout;
        for ( char color : line ) {
            made_cout[color] += 1;
        }
        
        // Initialize the result variable to store the total number of colors that can be made
        int res = 0;
        
        // Iterate over each color in the'made_cout' Counter
        for ( char color : made_cout ) {
            // Check if the color is not in the 'bought_count' Counter
            if ( bought_count.find ( color ) == bought_count.end ( ) ) {
                // If a color is not bought, print -1 and exit
                cout << - 1 << endl;
                return 0;
            }
            // Calculate the minimum of the counts of the current color in both 'bought_count' and'made_cout'
            // and add this to the result
            res += min ( bought_count[color], made_cout[color] );
        }
        
        // Print the final result
        cout << res << endl;
    }
    
    return 0;
}

