import java.util.Scanner ;  // Import the Scanner class for reading input

public class Main {
    public static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System.in ) ;  // Create a new Scanner object to read input
        
        int N = in.nextInt ( ) ;  // Read the first integer from the input, which represents the size of the grid
        int M = in.nextInt ( ) ;  // Read the second integer from the input, which represents the number of stones to be placed on the grid
        
        int [ ] [ ] black = new int [ N + 2 ] [ N + 2 ] ;  // Create a 2D array of size (N+2) x (N+2) to represent the grid
        
        for ( int m = 1 ; m <= M ; m ++ ) {  // Iterate M times, once for each stone to be placed
            int x = in.nextInt ( ) ;  // Read the x-coordinate of the next stone to be placed
            int y = in.nextInt ( ) ;  // Read the y-coordinate of the next stone to be placed
            
            for ( int xx = x - 1 ; xx <= x + 1 ; xx ++ ) {  // Iterate over all the neighboring cells in the x-direction
                for ( int yy = y - 1 ; yy <= y + 1 ; yy ++ ) {  // Iterate over all the neighboring cells in the y-direction
                    if ( ++ black [ xx ] [ yy ] == 9 ) {  // Check if the number of black cells around this cell becomes 9
                        System.out.println ( m ) ;  // If so, print the index of the stone that caused this condition and return
                        return ;
                    }
                }
            }
        }
        
        System.out.println ( "-1" ) ;  // If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return
    }
}
