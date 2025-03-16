
import java.io.* ; // Import class for input and output operations
import java.util.* ; // Import utility class

public class Main { // Define the main class

    public static void main ( String [ ] args ) { // Define the main method
        Scanner in = new Scanner ( System.in ) ; // Create a Scanner object to read input
        PrintWriter pw = new PrintWriter ( System.out ) ; // Create a PrintWriter object to write output

        int x1 = in.nextInt ( ) ; // Read the first x-coordinate
        int y1 = in.nextInt ( ) ; // Read the first y-coordinate
        int x2 = in.nextInt ( ) ; // Read the second x-coordinate
        int y2 = in.nextInt ( ) ; // Read the second y-coordinate

        if ( x1 == x2 ) { // Check if x1 and x2 are equal
            int dif = Math.abs ( y1 - y2 ) ; // Calculate the absolute difference between y1 and y2
            pw.println ( ( x1 + dif ) + " " + y1 + " " + ( x1 + dif ) + " " + y2 ) ; // Print the result to the standard output stream
        } else if ( y1 == y2 ) { // Check if y1 and y2 are equal
            int dif = Math.abs ( x1 - x2 ) ; // Calculate the absolute difference between x1 and x2
            pw.println ( ( x1 ) + " " + ( y1 + dif ) + " " + ( x2 ) + " " + ( y2 + dif ) ) ; // Print the result to the standard output stream
        } else if ( Math.abs ( x1 - x2 ) == Math.abs ( y1 - y2 ) ) { // Check if the absolute differences between x1 and x2 and y1 and y2 are equal
            pw.println ( x1 + " " + y2 + " " + x2+ " " + y1 ) ; // Print the result to the standard output stream
        } else { // If none of the above conditions are met
            pw.println ( - 1 ) ; // Print -1 to the standard output stream
        }

        pw.close ( ) ; // Close the PrintWriter object to free up system resources
    }

    static void debug ( Object...obj ) { // Define a static debug method
        System.err.println ( Arrays.deepToString ( obj ) ) ; // Print the contents of an array or an object to the standard error stream
    }
}