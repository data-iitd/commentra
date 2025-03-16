
#include <bits/stdc++.h>
using namespace std;

// Helper functions to pop and push elements from/to the heap
void hpop ( ) {
    // Write your code here
}

void hpush ( ) {
    // Write your code here
}

void solution ( ) {
    // Read the first line of input and create a Counter object for the bought colors
    string line;
    cin >> line;
    map < string , int > bought_count;
    for ( int i = 0 ; i < line.size ( ) ; i ++ ) {
        bought_count [ line [ i ] ] ++;
    }
    
    // Read the second line of input and create a Counter object for the colors to be made
    cin >> line;
    map < string , int > made_cout;
    for ( int i = 0 ; i < line.size ( ) ; i ++ ) {
        made_cout [ line [ i ] ] ++;
    }
    
    // Initialize the result variable to store the total number of colors that can be made
    int res = 0;
    
    // Iterate over each color in the 'made_cout' Counter
    for ( auto it = made_cout.begin ( ) ; it != made_cout.end ( ) ; it ++ ) {
        // Check if the color is not in the 'bought_count' Counter
        if ( bought_count.find ( it -> first ) == bought_count.end ( ) ) {
            // If a color is not bought, print -1 and exit
            cout << - 1 << endl;
            return;
        }
        // Calculate the minimum of the counts of the current color in both 'bought_count' and 'made_cout'
        // and add this to the result
        res += min ( bought_count [ it -> first ] , it -> second );
    }
    
    // Print the final result
    cout << res << endl;
}

int main ( ) {
    // Set the number of test cases to 1
    int t = 1;
    // Run the solution function for one test case
    for ( int i = 0 ; i < t ; i ++ ) {
        solution ( );
    }
    return 0;
}

