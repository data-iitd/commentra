import java.util.Scanner ;

public class Main {

    public static void main ( String [ ] args ) {
        // Create a new Scanner object to read input from the standard input stream
        Scanner scan = new Scanner ( System.in ) ;

        // Read the first integer `n` from the standard input stream and assign it to the variable `n`
        int n = scan.nextInt ( ) ;

        // Create a new long array `arr` of size `n`
        long [ ] arr = new long [ n ] ;

        // Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the array `arr`
        for ( int i = 0 ; i < n ; i ++ ) {
            arr [ i ] = scan.nextInt ( ) ;
        }

        // Initialize the variable `answer` with the absolute value of the first element of the array `arr`
        long answer = Math.abs ( arr [ 0 ] ) ;

        // Use a for loop to iterate over the remaining elements of the array `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
        for ( int i = 1 ; i < n ; i ++ ) {
            answer += Math.abs ( arr [ i ] - arr [ i - 1 ] ) ;
        }

        // Print the value of the variable `answer` to the standard output stream
        System.out.println ( answer ) ;

        // Close the Scanner object to release the system resources
        scan.close ( ) ;
    }
}