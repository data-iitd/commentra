
import java.util.* ; // Importing the utility class for input and output operations

public class Main { // Defining the main class

    public static boolean dfs ( int currpos , int[] arr , int target ) { // Defining the recursive depth-first search function
        if ( currpos ==target ) { // Base case: if the current position is the target position, return true
            return true ;
        }
        if ( currpos==arr.length+1 ) { // Base case: if the current position is out of the array bounds, return false
            return false ;
        }
        boolean teleport = dfs ( currpos+arr[currpos-1], arr, target ) ; // Recursive call: try to teleport to the previous position
        if ( teleport ) { // If teleportation was successful, return true
            return true ;
        }
        return false ; // If teleportation was not successful, return false
    }

    public static void main ( String[] args ) throws Exception { // Defining the main function
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object for reading input from the standard input
        int n = sc.nextInt ( ) ; // Reading the number of positions in the array from the standard input
        int goal = sc.nextInt ( ) ; // Reading the target position from the standard input
        int[] arr = new int[n-1] ; // Creating an array of size n-1 to store the positions of the teleportals
        for ( int i = 0 ; i < n-1 ; i ++ ) { // Reading the positions of the teleportals from the standard input and storing them in the array
            arr[i] = sc.nextInt ( ) ;
        }
        boolean isFound = dfs ( 1 , arr , goal ) ; // Calling the depth-first search function with the initial position and the target position
        if ( isFound ) { // If the target position was found, print "YES" to the standard output
            System.out.println ( "YES" ) ;
        } else { // If the target position was not found, print "NO" to the standard output
            System.out.println ( "NO" ) ;
        }
        sc.close ( ) ; // Closing the Scanner object
    }
}

These comments should provide a clear understanding of the code's logic and functionality.