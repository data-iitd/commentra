
import java.util.* ;  // Importing necessary Java utility classes
import java.lang.* ;  // Importing necessary Java language classes

public class Main {

    public static void main ( String [ ] args ) {
        Scanner scanner = new Scanner ( System.in ) ;  // Creating a Scanner object to read input from the console

        int h = scanner.nextInt ( ) ;  // Reading the height of the grid from the console
        int w = scanner.nextInt ( ) ;  // Reading the width of the grid from the console
        int n = scanner.nextInt ( ) ;  // Reading the number of steps from the console

        int sr = scanner.nextInt ( ) ;  // Reading the starting row of the safe zone from the console
        int sc = scanner.nextInt ( ) ;  // Reading the starting column of the safe zone from the console

        String s = scanner.next ( ) ;  // Reading the sequence of 'U' and 'D' representing the up and down movements
        String t = scanner.next ( ) ;  // Reading the sequence of 'L' and 'R' representing the left and right movements

        boolean end = false ;  // Initializing a boolean variable to keep track of whether the safe zone is valid or not
        int usafe = 1 ;  // Initializing two variables to keep track of the upper and lower boundaries of the safe zone
        int dsafe = h ;

        // The first for loop is to check the vertical boundaries of the safe zone based on the sequence 's'
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            if ( s.charAt ( i ) == 'U' ) {  // If the current character in the sequence 's' is 'U', increase the upper boundary by 1
                usafe ++ ;
            } else if ( s.charAt ( i ) == 'D' ) {  // If the current character in the sequence 's' is 'D', decrease the lower boundary by 1
                dsafe -- ;
            }
            if ( usafe > dsafe ) {  // If the upper boundary is greater than the lower boundary, the safe zone is not valid
                end = true ;
                break ;
            }
            if ( i > 0 ) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
                if ( t.charAt ( i - 1 ) == 'U' ) {
                    dsafe = Math.min ( dsafe + 1 , h ) ;  // If the previous character is 'U', increase the lower boundary by 1 to the minimum of the height
                } else if ( t.charAt ( i - 1 ) == 'D' ) {
                    usafe = Math.max ( usafe - 1 , 1 ) ;  // If the previous character is 'D', decrease the upper boundary by 1 to the maximum of 1
                }
            }
        }

        int lsafe = 1 ;  // Initializing two variables to keep track of the left and right boundaries of the safe zone
        int rsafe = w ;

        // The second for loop is to check the horizontal boundaries of the safe zone based on the sequence 't'
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            if ( s.charAt ( i ) == 'L' ) {  // If the current character in the sequence 's' is 'L', increase the left boundary by 1
                lsafe ++ ;
            } else if ( s.charAt ( i ) == 'R' ) {  // If the current character in the sequence 's' is 'R', decrease the right boundary by 1
                rsafe -- ;
            }
            if ( lsafe > rsafe ) {  // If the left boundary is greater than the right boundary, the safe zone is not valid
                end = true ;
                break ;
            }
            if ( i > 0 ) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
                if ( t.charAt ( i - 1 ) == 'L' ) {
                    rsafe = Math.min ( rsafe + 1 , w ) ;  // If the previous character is 'L', increase the right boundary by 1 to the minimum of the width
                } else if ( t.charAt ( i - 1 ) == 'R' ) {
                    lsafe = Math.max ( lsafe - 1 , 1 ) ;  // If the previous character is 'R', decrease the left boundary by 1 to the maximum of 1
                }
            }
        }

        if ( sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && ! end ) {  // Checking if the starting position of the safe zone is within the safe zone boundaries and the safe zone is valid
            System.out.println ( "YES" ) ;
        } else {
            System.out.println ( "NO" ) ;
        }
    }
}

These comments should provide a clear understanding of the logic behind each part of the code.