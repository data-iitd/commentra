import java.util.* ; 
import java.lang.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scanner = new Scanner ( System.in ) ; 
        
        // Reading input values
        int h = scanner.nextInt ( ) ; // Height of the grid
        int w = scanner.nextInt ( ) ; // Width of the grid
        int n = scanner.nextInt ( ) ; // Number of moves
        int sr = scanner.nextInt ( ) ; // Starting row
        int sc = scanner.nextInt ( ) ; // Starting column
        
        // Reading the moves
        String s = scanner.next ( ) ; // Sequence of moves in a string
        String t = scanner.next ( ) ; // Sequence of moves in a string
        
        // Initializing variables to track safe bounds
        boolean end = false ; // Flag to check if an unsafe condition is encountered
        int usafe = 1 ; // Safe upper bound for row
        int dsafe = h ; // Safe lower bound for row
        
        // Processing moves in reverse order for rows
        for ( int i = n - 1 ; i >= 0 ; i -- ) { 
            if ( s.charAt ( i ) == 'U' ) { 
                usafe ++ ; // Move up, increase upper safe bound
            } else if ( s.charAt ( i ) == 'D' ) { 
                dsafe -- ; // Move down, decrease lower safe bound
            } 
            if ( usafe > dsafe ) { // Check if upper safe bound exceeds lower safe bound
                end = true ; // Set end flag to true if unsafe
                break ; // Break out of the loop
            } 
            if ( i > 0 ) { // Check if it's not the first move
                if ( t.charAt ( i - 1 ) == 'U' ) { 
                    dsafe = Math.min ( dsafe + 1 , h ) ; // Adjust lower safe bound if previous move was up
                } else if ( t.charAt ( i - 1 ) == 'D' ) { 
                    usafe = Math.max ( usafe - 1 , 1 ) ; // Adjust upper safe bound if previous move was down
                } 
            } 
        } 
        
        // Initializing variables to track safe bounds for columns
        int lsafe = 1 ; // Safe left bound for column
        int rsafe = w ; // Safe right bound for column
        
        // Processing moves in reverse order for columns
        for ( int i = n - 1 ; i >= 0 ; i -- ) { 
            if ( s.charAt ( i ) == 'L' ) { 
                lsafe ++ ; // Move left, increase left safe bound
            } else if ( s.charAt ( i ) == 'R' ) { 
                rsafe -- ; // Move right, decrease right safe bound
            } 
            if ( lsafe > rsafe ) { // Check if left safe bound exceeds right safe bound
                end = true ; // Set end flag to true if unsafe
                break ; // Break out of the loop
            } 
            if ( i > 0 ) { // Check if it's not the first move
                if ( t.charAt ( i - 1 ) == 'L' ) { 
                    rsafe = Math.min ( rsafe + 1 , w ) ; // Adjust right safe bound if previous move was left
                } else if ( t.charAt ( i - 1 ) == 'R' ) { 
                    lsafe = Math.max ( lsafe - 1 , 1 ) ; // Adjust left safe bound if previous move was right
                } 
            } 
        } 
        
        // Checking if the final position is safe
        if ( sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && ! end ) { 
            System.out.println ( "YES" ) ; // Output YES if safe
        } else { 
            System.out.println ( "NO" ) ; // Output NO if not safe
        } 
    } 
}
