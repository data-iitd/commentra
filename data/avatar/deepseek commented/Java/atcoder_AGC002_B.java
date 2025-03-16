
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int N = sc.nextInt ( ) ; // Read the number of boxes
        int M = sc.nextInt ( ) ; // Read the number of moves
        Box [ ] B = new Box [ N ] ; 
        B [ 0 ] = new Box ( 1 , true ) ; // Initialize the first box with num=1 and red=true
        for ( int i = 1 ; i < N ; i ++ ) { 
            B [ i ] = new Box ( 1 , false ) ; // Initialize the rest of the boxes with num=1 and red=false
        }
        for ( int i = 0 ; i < M ; i ++ ) { 
            int x = sc.nextInt ( ) - 1 ; // Read the source box index (0-based)
            int y = sc.nextInt ( ) - 1 ; // Read the destination box index (0-based)
            B [ x ].moveTo ( B [ y ] ) ; // Move the box from source to destination
        }
        int counter = 0 ; 
        for ( Box b : B ) { 
            if ( b.red ) { 
                counter ++ ; // Count the number of red boxes
            }
        }
        System.out.println ( counter ) ; // Print the count of red boxes
    } 
} 

class Box { 
    public int num ; 
    public boolean red ; 
    public Box ( int n , boolean r ) { 
        num = n ; 
        red = r ; 
    } 
    public void moveTo ( Box other ) { 
        if ( num == 0 ) { 
            return ; // Do nothing if the box is already empty
        } else if ( num == 1 ) { 
            num = 0 ; // Set the current box to empty
            other.num ++ ; // Increment the destination box's number
            if ( red ) { 
                other.red = true ; // If the current box was red, make the destination box red
            } 
            red = false ; // The current box is no longer red
        } else { 
            num -- ; // Decrement the current box's number
            other.num ++ ; // Increment the destination box's number
            if ( red ) { 
                other.red = true ; // If the current box was red, make the destination box red
            } 
        } 
    } 
}

