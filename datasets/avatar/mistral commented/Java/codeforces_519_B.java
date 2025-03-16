import java.util.* ;  // Importing utility classes like Scanner
import java.io.* ;    // Importing I/O classes like PrintWriter and File

public class Main {
    public static void main ( String args [ ] ) throws IOException {
        // Main method is the entry point of the Java application
        // It has a void return type and a String array as its parameter
        // We are using the Scanner class to read input from the standard input
        // and the PrintWriter class to write the output to the standard output
        // We are also handling IOException to catch any I/O related errors

        Scanner sc = new Scanner ( System.in ) ;
        // Creating a new Scanner object and initializing it with the standard input stream

        int n = sc.nextInt ( ) ;
        // Reading the number of test cases (n) from the input using the nextInt() method of the Scanner class

        int a = 0 , b = 0 , c = 0 ;
        // Declaring and initializing three integer variables a, b, and c with zero values

        for ( int i = 0 ; i < n ; i ++ ) a += sc.nextInt ( ) ;
        // Using a for loop to read and sum up the first number in each test case using the nextInt() method of the Scanner class
        // and adding it to the variable 'a'

        for ( int i = 0 ; i < n - 1 ; i ++ ) b += sc.nextInt ( ) ;
        // Using a for loop to read and sum up the second number in each test case (except the last one) using the nextInt() method of the Scanner class
        // and adding it to the variable 'b'

        for ( int i = 0 ; i < n - 2 ; i ++ ) c += sc.nextInt ( ) ;
        // Using a for loop to read and sum up the third number in each test case (except the last two) using the nextInt() method of the Scanner class
        // and adding it to the variable 'c'

        int x = a - b ;
        // Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

        int y = b - c ;
        // Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

        System.out.println ( x ) ;
        System.out.println ( y ) ;
        // Printing the values of 'x' and 'y' to the standard output using the println() method of the PrintWriter class
    }
}