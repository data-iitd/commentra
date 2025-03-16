
#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    // Read the number of rows and columns from the input
    int H, W ;
    cin >> H >> W ;

    // Initialize a 2D char array 'A' to store the input grid
    char A [ H ] [ W ] ;

    // Initialize a Queue to store the cells to be processed
    queue < int [ ] > queue ;

    // Read the grid and initialize the queue with the starting points of 'B'
    for ( int i = 0 ; i < H ; i ++ ) {
        string row ;
        cin >> row ;
        for ( int j = 0 ; j < W ; j ++ ) {
            A [ i ] [ j ] = row.at ( j ) ;
            // If the cell contains '#', add its starting point to the queue
            if ( A [ i ] [ j ] == '#' ) {
                int [ ] start = { i, j, 0 } ;
                queue.push ( start ) ;
            }
        }
    }

    // Initialize a 2D int array 'flag' to mark the visited cells
    int flag [ H ] [ W ] ;

    // Initialize variables for the answer and the directions
    int ans = 0 ;
    int dx [ ] = { 1, - 1, 0, 0 } ;
    int dy [ ] = { 0, 0, 1, - 1 } ;

    // Process the queue and find the answer
    while (! queue.empty ( ) ) {
        int [ ] temp = queue.front ( ) ;
        queue.pop ( ) ;
        int y = temp [ 0 ] ;
        int x = temp [ 1 ] ;
        int depth = temp [ 2 ] ;

        // Process the neighboring cells
        for ( int i = 0 ; i < 4 ; i ++ ) {
            int newY = y + dy [ i ] ;
            int newX = x + dx [ i ] ;

            // If the cell is within the grid and hasn't been visited yet,
            // and contains a '.', mark it as visited and add it to the queue
            if ( 0 <= newY && newY <= H - 1 && 0 <= newX && newX <= W - 1 ) {
                if ( flag [ newY ] [ newX ] == 0 && A [ newY ] [ newX ] == '.' ) {
                    flag [ newY ] [ newX ] = 1 ;
                    int [ ] queue_add = { newY, newX, depth + 1 } ;
                    queue.push ( queue_add ) ;
                    ans = max ( ans, depth + 1 ) ;
                }
            }
        }
    }

    // Print the answer
    cout << ans << endl ;
}

