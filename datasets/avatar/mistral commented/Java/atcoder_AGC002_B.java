import java.util.Scanner ; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    public static void main ( String [ ] args ) { // Defining the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object for user input
        int N = sc.nextInt ( ) ; // Reading the first integer input from the user (number of boxes)
        int M = sc.nextInt ( ) ; // Reading the second integer input from the user (number of moves)
        Box [ ] B = new Box [ N ] ; // Creating an array of Box objects with size N

        // Initializing the first box with red color
        B [ 0 ] = new Box ( 1 , true ) ;

        // Initializing the remaining boxes with red color set to false
        for ( int i = 1 ; i < N ; i ++ ) {
            B [ i ] = new Box ( 1 , false ) ;
        }

        // Reading the moves from the user and performing them on the boxes
        for ( int i = 0 ; i < M ; i ++ ) {
            int x = sc.nextInt ( ) - 1 ; // Reading the x-coordinate of the source box
            int y = sc.nextInt ( ) - 1 ; // Reading the y-coordinate of the destination box
            B [ x ].moveTo ( B [ y ] ) ; // Moving the box at index x to the box at index y
        }

        // Counting the number of red boxes
        int counter = 0 ;
        for ( Box b : B ) { // Iterating through all the boxes in the array
            if ( b.red ) { // If the current box has red color
                counter ++ ; // Increment the counter
            }
        }

        // Printing the result
        System.out.println ( counter ) ;
    }
}

class Box { // Defining the Box class
    public int num ; // Initializing the number property
    public boolean red ; // Initializing the red property

    public Box ( int n , boolean r ) { // Constructor for initializing the Box object
        num = n ;
        red = r ;
    }

    // Method for moving the box to another box
    public void moveTo ( Box other ) {
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
}
