
import java.io.OutputStream ; // Output stream to write output
import java.io.IOException ; // For handling I/O exceptions
import java.io.InputStream ; // Input stream to read input
import java.util.Scanner ; // For reading input

public class Main {
    // Main method to start the program
    public static void main ( String [ ] args ) {
        InputStream inputStream = System.in ; // Initialize input stream
        OutputStream outputStream = System.out ; // Initialize output stream
        Scanner in = new Scanner ( inputStream ) ; // Initialize scanner for reading input
        PrintWriter out = new PrintWriter ( outputStream ) ; // Initialize print writer for writing output

        AStationAndBus solver = new AStationAndBus ( ) ; // Create an instance of the solver class
        solver.solve ( 1 , in , out ) ; // Call the solve method with test number, input scanner, and output print writer

        out.close ( ) ; // Close the output print writer
    }

    static class AStationAndBus {
        // Inner class to solve the problem

        public void solve ( int testNumber , Scanner in , PrintWriter out ) {
            // Method to solve the problem

            String s = in.next ( ) ; // Read the next input string

            // Check if the string contains both 'A' and 'B'
            if ( s.contains ( "A" ) && s.contains ( "B" ) ) {
                out.println ( "Yes" ) ; // Print "Yes" if both characters are present
            } else {
                out.println ( "No" ) ; // Print "No" if either character is missing
            }
        }
    }
}

