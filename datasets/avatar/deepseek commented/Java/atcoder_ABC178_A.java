
import java.util.* ; 
import java.io.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scan = new Scanner ( System.in ) ; // Create a Scanner object to read input from the standard input stream
        int x = Integer.parseInt ( scan.next ( ) ) ; // Read an integer from the input
        boolean bool = x == 1 ? true : false ; // Convert the integer x to a boolean value bool using a ternary operator
        int result = ! bool ? 1 : 0 ; // Calculate the result based on the boolean value bool
        PrintWriter out = new PrintWriter ( System.out ) ; // Create a PrintWriter object to print the result to the standard output stream
        out.println ( result ) ; // Print the result
        out.flush ( ) ; // Ensure the output is flushed to the console
    } 
}

