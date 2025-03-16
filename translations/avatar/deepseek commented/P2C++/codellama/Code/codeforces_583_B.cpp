
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ( ) {
    // Read the number of elements from the user
    int n;
    cin >> n;
    // Read the list of integers from the user input
    vector < int > a;
    for ( int i = 0; i < n; i++ ) {
        int temp;
        cin >> temp;
        a.push_back ( temp );
    }
    
    // Initialize variables to track the current level and the number of turns
    int current_level = 0;
    int counter = 0;
    int counter_turns = - 1;
    
    // Start a while loop that continues until all elements are processed
    while ( counter < a.size ( ) ) {
        // Increment the turn counter
        counter_turns += 1;
        // Iterate over the list 'a' to process each element
        for ( int i = 0; i < a.size ( ); i++ ) {
            // Check if the element is not -1 and is less than or equal to the current level
            if ( a [ i ] != - 1 && a [ i ] <= current_level ) {
                // Increment the counter and mark the element as processed
                counter += 1;
                a [ i ] = - 1;
            }
        }
        // Reverse the list 'a' to process elements in a different order in the next iteration
        reverse ( a.begin ( ), a.end ( ) );
    }
    
    // Print the number of turns taken to process all elements
    cout << counter_turns << endl;
    return 0;
}
