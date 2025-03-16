#include <iostream>

using namespace std ; // Using the standard namespace

class Box { // Defining the Box class
    public:
        int num ; // Initializing the number property
        bool red ; // Initializing the red property

        Box ( int n , bool r ) { // Constructor for initializing the Box object
            num = n ;
            red = r ;
        }

        // Method for moving the box to another box
        void moveTo ( Box & other ) {
            if ( num ==0 ) { // If the current box is empty
                return ; // Do nothing
            } else if ( num == 1 ) { // If the current box has only one item
                num = 0 ; // Setting the current box to be empty
                other.num ++ ; // Incrementing the number of items in the other box
                if ( red ) { // If the current box was red
                    other.red = true ; // Setting the other box to be red
                }
                red = false ; // Setting the current box to be empty and not red
            } else { // If the current box has more than one item
                num -- ; // Decrementing the number of items in the current box
                other.num ++ ; // Incrementing the number of items in the other box
                if ( red ) { // If the current box was red
                    other.red = true ; // Setting the other box to be red
                }
            }
        }
};

int main ( ) { // Defining the main method
    int N , M ; // Initializing the number of boxes and the number of moves
    cin >> N >> M ; // Reading the number of boxes and the number of moves from the user
    Box * B = new Box [ N ] ; // Creating an array of Box objects with size N

    // Initializing the first box with red color
    B [ 0 ] = Box ( 1 , true ) ;

    // Initializing the remaining boxes with red color set to false
    for ( int i = 1 ; i < N ; i ++ ) {
        B [ i ] = Box ( 1 , false ) ;
    }

    // Reading the moves from the user and performing them on the boxes
    for ( int i = 0 ; i < M ; i ++ ) {
        int x , y ; // Initializing the x-coordinate and the y-coordinate of the source and destination boxes
        cin >> x >> y ; // Reading the x-coordinate and the y-coordinate of the source and destination boxes from the user
        B [ x ].moveTo ( B [ y ] ) ; // Moving the box at index x to the box at index y
    }

    // Counting the number of red boxes
    int counter = 0 ;
    for ( int i = 0 ; i < N ; i ++ ) { // Iterating through all the boxes in the array
        if ( B [ i ].red ) { // If the current box has red color
            counter ++ ; // Increment the counter
        }
    }

    // Printing the result
    cout << counter << endl ;

    return 0 ; // Returning 0 to indicate that the program ended successfully
}

