
#include <iostream>  // Include the necessary header file for input/output operations

using namespace std;  // Use the standard namespace for input/output operations

int main ( ) {
    int N, M, x, y;  // Declare the necessary variables to read input and store the grid size and the number of stones
    
    cin >> N >> M;  // Read the grid size and the number of stones from the input
    
    int black [ N + 2 ] [ N + 2 ] = { 0 } ;  // Create a 2D array of size (N+2) x (N+2) to represent the grid
    
    for ( int m = 1 ; m <= M ; m ++ ) {  // Iterate M times, once for each stone to be placed
        cin >> x >> y;  // Read the x-coordinate and the y-coordinate of the next stone to be placed
        
        for ( int xx = x - 1 ; xx <= x + 1 ; xx ++ ) {  // Iterate over all the neighboring cells in the x-direction
            for ( int yy = y - 1 ; yy <= y + 1 ; yy ++ ) {  // Iterate over all the neighboring cells in the y-direction
                if ( ++ black [ xx ] [ yy ] == 9 ) {  // Check if the number of black cells around this cell becomes 9
                    cout << m << endl;  // If so, print the index of the stone that caused this condition and return
                    return 0;
                }
            }
        }
    }
    
    cout << "-1" << endl;  // If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return
    
    return 0;  // End the program
}

