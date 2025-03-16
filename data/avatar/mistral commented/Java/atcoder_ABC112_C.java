import java.util.Scanner ;  // Importing the Scanner class for reading input
import java.util.stream.IntStream ;  // Importing IntStream for using parallel streams

public class Main {
    private static final int MAX = 100 ;  // Defining a constant MAX with value 100

    public static void main ( String [ ] args ) {  // Main method to start the program
        try ( Scanner scanner = new Scanner ( System.in ) ) {  // Creating a try block to handle exceptions while reading input
            int n = scanner.nextInt() ;  // Reading the number of elements n from the standard input
            int [] x = new int [ n ] , y = new int [ n ] , h = new int [ n ] ;  // Creating arrays x, y, and h of size n

            IntStream.range(0, n).forEach(i -> {  // Using IntStream to read and initialize the arrays in parallel
                x[i] = scanner.nextInt() ;
                y[i] = scanner.nextInt() ;
                h[i] = scanner.nextInt() ;
            });

            for ( int i = 0 ; i <= MAX ; i ++ ) {  // Outer loop to iterate through all possible positions (i, j)
                for ( int j = 0 ; j <= MAX ; j ++ ) {  // Inner loop to check all possible positions (i, j)
                    int ch = check(n, x, y, h, i, j) ;  // Calling the check method to calculate the height of the water at position (i, j)
                    if ( ch > 0 ) {  // If the height is greater than 0, print the position and height
                        System.out.println(i + " " + j + " " + ch) ;
                    }
                }
            }
        }
    }

    private static int check ( int n , int [ ] x , int [ ] y , int [ ] h , int cx , int cy ) {  // Method to check the height of water at position (cx, cy)
        int ch = - 1 ;  // Initializing the height to -1

        for ( int i = 0 ; i < n ; i ++ ) {  // Loop to iterate through all elements in the arrays x, y, and h
            if ( h[i] > 0 ) {  // If the height of the current element is greater than 0
                ch = Math.abs(x[i] - cx) + Math.abs(y[i] - cy) + h[i] ;  // Calculate the distance and height of the current element and update the height if it's closer
                break ;  // Exit the loop once the closest element is found
            }
        }

        for ( int i = 0 ; i < n ; i ++ ) {  // Loop to check if all elements have the same height as the closest one
            if ( h[i] != Math.max(ch - Math.abs(x[i] - cx) - Math.abs(y[i] - cy), 0) ) {  // If the height is different, return -1 to indicate an error
                return -1 ;
            }
        }

        return ch ;  // Return the height of the water at position (cx, cy)
    }
}
