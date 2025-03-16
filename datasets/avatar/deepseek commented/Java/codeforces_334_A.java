import java.io.* ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; // Initialize Scanner for input
        PrintWriter pw = new PrintWriter ( System.out ) ; // Initialize PrintWriter for output
        
        int n = in.nextInt ( ) ; // Read the size of the grid
        int square = n * n ; // Calculate the total number of elements
        
        ArrayList < Integer > odd = new ArrayList < > ( ) ; // List to store odd numbers
        ArrayList < Integer > even = new ArrayList < > ( ) ; // List to store even numbers
        
        // Separating numbers into odd and even lists
        for ( int i = 1 ; i <= square ; i ++ ) { 
            if ( i % 2 == 0 ) { 
                even.add ( i ) ; // Add even numbers to the even list
            } else { 
                odd.add ( i ) ; // Add odd numbers to the odd list
            } 
        }
        
        int loop = square / n ; // Calculate the number of rows/columns
        int div = loop / 2 ; // Calculate half the number of elements in each row/column
        
        debug ( div ) ; // Debugging statement to print the value of div
        
        // Nested loops to generate the pattern
        for ( int i = 1 ; i <= loop ; i ++ ) { 
            for ( int j = 0 ; j < div ; j ++ ) { 
                if ( i % 2 == 1 ) { 
                    pw.print ( odd.remove ( 0 ) + " " + ( even.remove ( even.size ( ) - 1 ) ) + " " ) ; // Print odd and even numbers in reverse order for odd rows
                } else { 
                    pw.print ( even.remove ( 0 ) + " " + ( odd.remove ( odd.size ( ) - 1 ) ) + " " ) ; // Print even and odd numbers in reverse order for even rows
                } 
            } 
            pw.println ( ) ; // Move to the next line after each row
        } 
        
        pw.close ( ) ; // Close the PrintWriter to flush and release resources
    } 
    
    static void debug ( Object...obj ) { 
        System.err.println ( Arrays.deepToString ( obj ) ) ; // Debugging statement to print the object array
    } 
}
