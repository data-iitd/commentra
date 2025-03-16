
import java.util.* ;

// Create a Scanner object to read input from the standard input
public class Main {

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;

        // Read the number of rows and columns from the input
        int H = sc.nextInt ( ) ;
        int W = sc.nextInt ( ) ;

        // Initialize a 2D char array 'A' to store the input grid
        char [ ] [ ] A = new char [ H ] [ W ] ;

        // Initialize a Queue to store the cells to be processed
        Queue < int [ ] > queue = new ArrayDeque < int [ ] > ( ) ;

        // Read the grid and initialize the queue with the starting points of 'B'
        for ( int i = 0 ; i < H ; i ++ ) {
            String row = sc.next ( ) ;
            for ( int j = 0 ; j < W ; j ++ ) {
                A [ i ] [ j ] = row.charAt ( j ) ;
                // If the cell contains '#', add its starting point to the queue
                if ( A [ i ] [ j ] == '#' ) {
                    int [ ] start = { i , j , 0 } ;
                    queue.add ( start ) ;
                }
            }
        }

        // Initialize a 2D int array 'flag' to mark the visited cells
        int [ ] [ ] flag = new int [ H ] [ W ] ;

        // Initialize variables for the answer and the directions
        int ans = 0 ;
        int [ ] dx = { 1 , - 1 , 0 , 0 } ;
        int [ ] dy = { 0 , 0 , 1 , - 1 } ;

        // Process the queue and find the answer
        while ( ! queue.isEmpty ( ) ) {
            int [ ] temp = queue.remove ( ) ;
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
                        int [ ] queue_add = { newY , newX , depth + 1 } ;
                        queue.add ( queue_add ) ;
                        ans = Math.max ( ans , depth + 1 ) ;
                    }
                }
            }
        }

        // Print the answer
        System.out.println ( ans ) ;
    }
}

These comments should provide a clear understanding of the code's logic and purpose. Let me know if you need any further clarification.