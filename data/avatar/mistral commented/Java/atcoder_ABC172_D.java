import java.util.Scanner ; // We import the Scanner class to read input from the standard input stream

public class Main {
    public static void main ( String [ ] args ) { // The main method is the entry point of the program
        Scanner sc = new Scanner ( System.in ) ; // We create a new Scanner object to read input from the standard input stream
        
        int n ; // We declare an integer variable n to store the number of terms
        long ans = 0 ; // We initialize a long variable ans to 0, which will be used to store the answer

        // We read an integer n from the standard input stream using the nextInt method of the Scanner class
        n = sc.nextInt ( ) ;

        for ( int i = 1 ; i < n + 1 ; i ++ ) { // We start a for loop that iterates from 1 to n
            ans += ( long ) i * ( ( long ) n / ( long ) i ) * ( ( ( long ) n / ( long ) i ) + 1 ) / 2 ; // In each iteration of the loop, we calculate the contribution of i to the answer using the formula i * (n / i) * ((n / i) + 1) / 2 and add it to the ans variable
        }

        System.out.println ( ans ) ; // After the loop finishes, we print the value of ans to the standard output stream using the println method of the PrintStream class

        sc.close ( ) ; // We close the Scanner object to release the system resources
    }
}
