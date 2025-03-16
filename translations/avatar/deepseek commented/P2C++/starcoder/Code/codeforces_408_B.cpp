
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    // Set the number of test cases to 1
    int t = 1;
    // Run the solution function for one test case
    for ( int _ = 0 ; _ < t ; _++ ) {
        solution ( );
    }
}

void solution ( ) {
    // Read the first line of input and create a Counter object for the bought colors
    string line;
    getline ( cin, line );
    unordered_map < char, int > bought_count;
    for ( char c : line ) {
        bought_count [ c ]++;
    }
    
    // Read the second line of input and create a Counter object for the colors to be made
    getline ( cin, line );
    unordered_map < char, int > made_cout;
    for ( char c : line ) {
        made_cout [ c ]++;
    }
    
    // Initialize the result variable to store the total number of colors that can be made
    int res = 0;
    
    // Iterate over each color in the'made_cout' Counter
    for ( auto & color : made_cout ) {
        // Check if the color is not in the 'bought_count' Counter
        if ( bought_count.find ( color.first ) == bought_count.end ( ) ) {
            // If a color is not bought, print -1 and exit
            cout << -1 << endl;
            return;
        }
        // Calculate the minimum of the counts of the current color in both 'bought_count' and'made_cout'
        // and add this to the result
        res += min ( bought_count [ color.first ], color.second );
    }
    
    // Print the final result
    cout << res << endl;
}

