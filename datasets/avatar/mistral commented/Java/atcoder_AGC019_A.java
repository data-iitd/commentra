import java.util.* ;                   // Importing the utility class Scanner from java.util package
import static java.lang.System.* ;      // Importing static methods from java.lang.System package

public class Main {                     // Defining the main class named Main
    public static void main ( String [ ] args ) { // Defining the main method which is the entry point of the program
        Scanner sc = new Scanner ( System.in ) ; // Creating an instance of Scanner class to read input from the standard input

        long Q = sc.nextLong ( ) ;          // Reading the first long value Q from the standard input
        long H = sc.nextLong ( ) ;          // Reading the second long value H from the standard input
        long S = sc.nextLong ( ) ;          // Reading the third long value S from the standard input
        long D = sc.nextLong ( ) ;          // Reading the fourth long value D from the standard input
        long N = sc.nextLong ( ) ;          // Reading the fifth long value N from the standard input

        long onePrice = Math.min ( Math.min ( Q * 4 , H * 2 ) , S ) ; // Calculating the minimum price per item among Q*4, H*2, and S

        if ( ( double ) onePrice <= ( double ) D / 2 ) { // Checking if the minimum price per item is less than or equal to half of the deposit amount
            out.println ( N * onePrice ) ;              // If true, printing the result as the product of N and the minimum price per item
        } else {                                        // If false, the following block is executed
            out.println ( ( N / 2 ) * D + ( N % 2 ) * onePrice ) ; // Calculating and printing the result as the sum of half of N multiplied by the deposit amount and the remaining N (if any) multiplied by the minimum price per item
        }
    }
}
