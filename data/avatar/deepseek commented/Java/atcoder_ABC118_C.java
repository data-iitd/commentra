
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner object to read input
        int n = sc.nextInt ( ) ; // Read the number of integers
        ArrayList < Integer > a = new ArrayList < > ( ) ; // Create an ArrayList to store integers
        
        if ( n == 1 ) { // Check if there is only one integer
            System.out.println ( sc.nextInt ( ) ) ; // Read and print the single integer
            System.exit ( 0 ) ; // Exit the program
        }
        
        for ( int i = 0 ; i < n ; i ++ ) { // Read n integers and add them to the ArrayList
            a.add ( sc.nextInt ( ) ) ; 
        }
        
        Collections.sort ( a ) ; // Sort the ArrayList
        
        if ( a.get ( a.size ( ) - 1 ) == 0 ) { // Check if the largest element is 0
            System.out.println ( 0 ) ; // Print 0 and exit the program
            System.exit ( 0 ) ; 
        }
        
        int ans = 0 ; // Initialize the result variable
        
        while ( true ) { // Enter an infinite loop to process the ArrayList
            if ( a.size ( ) == 1 ) { // Check if there is only one element left
                ans = a.get ( 0 ) ; // Assign the single element to ans
                break ; // Exit the loop
            }
            a = func ( a ) ; // Call the func method to update the ArrayList
        }
        
        System.out.println ( ans ) ; // Print the final result
    }
    
    private static ArrayList < Integer > func ( ArrayList < Integer > A ) { 
        ArrayList < Integer > a = A ; // Create a copy of the input ArrayList
        int min = 0 ; // Initialize the minimum variable
        
        for ( int i = 0 ; i < a.size ( ) ; i ++ ) { // Iterate through the ArrayList
            if ( a.get ( i ) == 0 ) { // Remove elements that are zero
                a.remove ( i ) ; 
                i -- ; // Adjust the index after removal
            } else { // Process non-zero elements
                if ( min != 0 ) { // Check if min is not zero
                    a.set ( i , a.get ( i ) % min ) ; // Perform modulo operation
                    if ( a.get ( i ) == 1 ) { // Check if the result is 1
                        System.out.println ( 1 ) ; // Print 1 and exit the program
                        System.exit ( 0 ) ; 
                    }
                } else { // Find the minimum non-zero element
                    min = a.get ( i ) ; 
                }
            }
        }
        
        Collections.sort ( a ) ; // Sort the ArrayList
        return a ; // Return the updated ArrayList
    }
}

